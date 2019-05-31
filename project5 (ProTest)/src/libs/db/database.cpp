#include "../../headers/tests_main_header.h"
using namespace std;

extern sqlite3 *db;

int db_open()
{
    if(sqlite3_open("data.sqlite", &db) != SQLITE_OK)
        return -1;
    return 0;
}

int db_open(const char * name)
{
    if(sqlite3_open(name, &db) != SQLITE_OK)
        return -1;
    return 0;
}

void db_close()
{
    int rc = sqlite3_close_v2(db);
    if (rc == SQLITE_BUSY) {
        fprintf(stderr, "Database is busy. Call back later!\n");
    }

    db = nullptr;
}

int db_delete_question(int id)
{
    int rc;
    sqlite3_stmt * st = nullptr;

    rc = sqlite3_prepare_v2(db, "DELETE FROM `questions` WHERE id = ?", -1, &st, nullptr);
    sqlite3_bind_int( st, 1, id );

    if (rc != SQLITE_OK)
        return -1;

    rc= sqlite3_step(st);
    if (rc != SQLITE_DONE || sqlite3_changes(db) != 1)
        return -1;

    return SQLITE_OK;
}

int db_delete_user(int id)
{
    int rc;
    sqlite3_stmt * st = nullptr;

    rc = sqlite3_prepare_v2(db, "DELETE FROM `users` WHERE id = ?", -1, &st, nullptr);
    sqlite3_bind_int( st, 1, id );

    if (rc != SQLITE_OK)
        return -1;

    rc= sqlite3_step(st);
    if (rc != SQLITE_DONE || sqlite3_changes(db) != 1)
        return -1;

    rc = sqlite3_prepare_v2(db, "DELETE FROM `marks` WHERE user_id = ?", -1, &st, nullptr);
    sqlite3_bind_int( st, 1, id );

    if (rc != SQLITE_OK)
        return -1;

    rc= sqlite3_step(st);
    if (rc != SQLITE_DONE || sqlite3_changes(db) != 1)
        return -1;

    return SQLITE_OK;
}

User db_get_user(int id)
{
    sqlite3_stmt * st = nullptr;

    User user = {0};

    int rc = sqlite3_prepare_v2(db, "SELECT * FROM `users` WHERE id=?;", -1, &st, nullptr);
    if (rc != SQLITE_OK)
        return user;

    rc = sqlite3_bind_int(st, 1, id);
    if (rc != SQLITE_OK)
        return user;

    rc = sqlite3_step(st);
    if (rc != SQLITE_DONE && rc != SQLITE_OK && rc != SQLITE_ROW)
        return user;

    int num = sqlite3_column_int(st, 0);
    user.id = num;

    char *text = strdup((char *) sqlite3_column_text(st, 1));
    strcpy(user.login, text);
    free(text);
    // skip password column
    text = strdup((char *) sqlite3_column_text(st, 3));
    strcpy( user.first_name, text);
    free(text);
    text = strdup((char *) sqlite3_column_text(st, 4));
    strcpy( user.last_name, text);
    free(text);

    num = sqlite3_column_int(st, 5);
    user.admin = num != 0;

    return user;
}

Marks db_get_user_marks(int user_id)
{
    sqlite3_stmt * st = nullptr;

    Marks marks = {0};

    int rc = sqlite3_prepare_v2(db, "SELECT * FROM `marks` WHERE user_id=?;", -1, &st, nullptr);
    if (rc != SQLITE_OK)
        return marks;

    rc = sqlite3_bind_int(st, 1, user_id);
    if (rc != SQLITE_OK)
        return marks;

    rc = sqlite3_step(st);

    if (rc != SQLITE_DONE && rc != SQLITE_OK && rc != SQLITE_ROW)
        return marks;

    marks.user_id = sqlite3_column_int(st, 0);

    for (int i = 0; i < 10; i++)
        marks.values[i] = sqlite3_column_int(st, i+1);

    return marks;
}

User db_login(char * login, char * password)
{
    int rc;
    User user = {};

    string pass_hash = sha256(password);

    sqlite3_stmt * st = nullptr;
    rc = sqlite3_prepare_v2(db, "SELECT COUNT(*) FROM `users` WHERE login = ? AND pass = ?", -1, &st, nullptr);
    if (rc != SQLITE_OK)
        return user;

    rc = sqlite3_bind_text(st, 1, login, -1, SQLITE_STATIC);
    rc = sqlite3_bind_text(st, 2, pass_hash.c_str(), -1, SQLITE_STATIC);

    if (rc != SQLITE_OK)
        return user;

    rc = sqlite3_step(st);

    int res = sqlite3_column_int(st, 0);

    if(res != 1)
        // user not found
        return user;

    rc = sqlite3_prepare_v2(db, "SELECT * FROM `users` WHERE login = ?", -1, &st, nullptr);
    rc = sqlite3_bind_text(st, 1, login, -1, SQLITE_STATIC);

    if (rc != SQLITE_OK)
        // Oops, something went wrong
        return user;

    sqlite3_step(st);

    // write user data to object
    user.id = sqlite3_column_int(st, 0);
    strcpy(user.login, (char *) sqlite3_column_text(st, 1));
    // skip password column
    strcpy(user.first_name, (char *) sqlite3_column_text(st, 3));
    strcpy(user.last_name, (char *) sqlite3_column_text(st, 4));
    user.admin = sqlite3_column_int(st, 5) != 0;

    return user;
}

Question * db_get_test(int theme)
{
    int rc;
    auto * questions = new Question[10];

    sqlite3_stmt * st = nullptr;
    rc = sqlite3_prepare_v2(db, "SELECT * FROM `questions` WHERE `theme`=? ORDER BY random() LIMIT 10", -1, &st, nullptr);
    if (rc != SQLITE_OK)
        return nullptr;

    rc = sqlite3_bind_int(st, 1, theme);
    if (rc != SQLITE_OK)
        return nullptr;

    int i = 0, num;
    rc = sqlite3_step(st);

    while (rc != SQLITE_DONE && rc != SQLITE_OK && i < 10)
    {
        questions[i].id = sqlite3_column_int(st, 0);
        questions[i].theme = sqlite3_column_int(st, 1);
        questions[i].correct = sqlite3_column_int(st, 7);

        strcpy( questions[i].value, (char *) sqlite3_column_text(st, 2) );
        for (int j = 3; j < 7; j++)
            strcpy( questions[i].ans[j-3], (char *) sqlite3_column_text(st, j) );

        rc = sqlite3_step(st);
        i++;
    }

    if (i != 10) {
        delete(questions);
        return nullptr;
    } else {
        return questions;        
    }
}

Question * db_get_questions(int * size)
{
    sqlite3_stmt * st = nullptr;
    *size = 0; // by default

    // get number of questions
    int rc = sqlite3_prepare_v2(db, "SELECT count(*) FROM `questions`;", -1, &st, nullptr);

    if (rc != SQLITE_OK)
        return nullptr;
    rc = sqlite3_step(st);
    if (rc != SQLITE_DONE && rc != SQLITE_ROW)
        return nullptr;

    int n = sqlite3_column_int(st, 0);

    if (n <= 0)
        return nullptr;

    *size = n;
    auto questions = new Question[n];

    rc = sqlite3_prepare_v2(db, "SELECT * FROM `questions`;", -1, &st, nullptr);
    if (rc != SQLITE_OK)
        return nullptr;

    int i = 0;
    rc = sqlite3_step(st);

    while (rc != SQLITE_DONE && rc != SQLITE_OK)
    {
        questions[i].id = sqlite3_column_int(st, 0);
        questions[i].theme = sqlite3_column_int(st, 1);
        questions[i].correct = sqlite3_column_int(st, 7);

        strcpy( questions[i].value, (char *) sqlite3_column_text(st, 2) );

        for (int j = 3; j < 7; j++) 
            strcpy( questions[i].ans[j-3], (char *) sqlite3_column_text(st, j) );

        rc = sqlite3_step(st);
        i++;
    }

    return questions;
}

Question * db_get_questions(int * size, int theme)
{
    sqlite3_stmt * st = nullptr;
    *size = 0; // by default

    // get number of questions
    int rc = sqlite3_prepare_v2(db, "SELECT count(*) FROM `questions` WHERE `theme`=?;", -1, &st, nullptr);

    if (rc != SQLITE_OK)
        return nullptr;

    rc = sqlite3_bind_int(st, 1, theme);
    if (rc != SQLITE_OK)
        return nullptr;

    rc = sqlite3_step(st);
    if (rc != SQLITE_DONE && rc != SQLITE_ROW)
        return nullptr;

    int n = sqlite3_column_int(st, 0);

    if (n <= 0)
        return nullptr;

    *size = n;
    auto questions = new Question[n];

    rc = sqlite3_prepare_v2(db, "SELECT * FROM `questions` WHERE `theme` = ?;", -1, &st, nullptr);
    if (rc != SQLITE_OK)
        return nullptr;

    rc = sqlite3_bind_int(st, 1, theme);
    if (rc != SQLITE_OK)
        return nullptr;

    int i = 0, num;
    rc = sqlite3_step(st);

    while (rc != SQLITE_DONE && rc != SQLITE_OK)
    {
        questions[i].id = sqlite3_column_int(st, 0);
        questions[i].theme = sqlite3_column_int(st, 1);
        questions[i].correct = sqlite3_column_int(st, 7);
        strcpy( questions[i].value, (char *) sqlite3_column_text(st, 2) );

        for (int j = 3; j < 7; j++)
            strcpy( questions[i].ans[j-3], (char *) sqlite3_column_text(st, j) );

        rc = sqlite3_step(st);
        i++;
    }

    return questions;
}

Question db_get_question_by_id(int id)
{
    sqlite3_stmt * st = nullptr;

    Question q = {};

    int rc = sqlite3_prepare_v2(db, "SELECT * FROM `questions` WHERE id = ?;", -1, &st, nullptr);
    if (rc != SQLITE_OK)
        return q;

    rc = sqlite3_bind_int(st, 1, id);
    if (rc != SQLITE_OK)
        return q;

    rc = sqlite3_step(st);
    if (rc != SQLITE_DONE && rc != SQLITE_OK && rc != SQLITE_ROW)
        return q;

    q.id = sqlite3_column_int(st, 0);
    q.theme = sqlite3_column_int(st, 1);
    q.correct = sqlite3_column_int(st, 7);

    strcpy( q.value, (char *) sqlite3_column_text(st, 2) );

    for (int j = 3; j < 7; j++)
        strcpy( q.ans[j-3], (char *) sqlite3_column_text(st, j) );

    return q;
}

int db_add_user(User user, char * password)
{
    int rc;
    sqlite3_stmt * st = nullptr;

    string pass_hash = sha256(password);

    rc = sqlite3_prepare_v2(db, "INSERT INTO `users` VALUES (NULL, ?, ?, ?, ?, 0)", -1, &st, nullptr);
    sqlite3_bind_text( st, 1, user.login, -1, SQLITE_STATIC);
    sqlite3_bind_text( st, 2, pass_hash.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text( st, 3, user.first_name, -1, SQLITE_STATIC);
    sqlite3_bind_text( st, 4, user.last_name, -1, SQLITE_STATIC);

    if (rc != SQLITE_OK)
        return -1;

    rc = sqlite3_step(st);

    if (rc != SQLITE_DONE)
        return -1;
    
    rc = sqlite3_prepare_v2(db, "INSERT INTO 'marks' VALUES(last_insert_rowid(),0,0,0,0,0,0,0,0,0,0)", -1, &st, nullptr);

    if (rc != SQLITE_OK)
        return -1;

    rc = sqlite3_step(st);

    if (rc != SQLITE_DONE)
        return -1;


    return (int) sqlite3_last_insert_rowid(db);
}

int db_add_admin(User user, char * password)
{
    int id = db_add_user(user, password);
    if (id == -1)
        return -1;

    int rc = db_grant_admin(id);
    if (rc == SQLITE_OK)
        return id;
    else
        return -1;
}

int db_add_question(Question question)
{
    int rc;
    sqlite3_stmt * st = nullptr;

    rc = sqlite3_prepare_v2(db, "INSERT INTO `questions` VALUES (NULL, ?, ?, ?, ?, ?, ?, ?)", -1, &st, nullptr);
    sqlite3_bind_int( st, 1, question.theme);
    sqlite3_bind_text( st, 2, question.value, -1, SQLITE_STATIC);
    sqlite3_bind_text( st, 3, question.ans[0], -1, SQLITE_STATIC);
    sqlite3_bind_text( st, 4, question.ans[1], -1, SQLITE_STATIC);
    sqlite3_bind_text( st, 5, question.ans[2], -1, SQLITE_STATIC);
    sqlite3_bind_text( st, 6, question.ans[3], -1, SQLITE_STATIC);
    sqlite3_bind_int( st, 7, question.correct);

    if (rc != SQLITE_OK)
        return -1;

    rc = sqlite3_step(st);
    if (rc != SQLITE_DONE && rc != SQLITE_OK)
        return -1;

    rc = sqlite3_prepare_v2(db, "SELECT last_insert_rowid()", -1, &st, nullptr);

    if (rc != SQLITE_OK)
        return -1;

    rc= sqlite3_step(st);
    if (rc != SQLITE_DONE && rc != SQLITE_OK && rc != SQLITE_ROW)
        return -1;

    int res = sqlite3_column_int(st, 0);

    return res;
}

Question * db_get_final_test()
{
    int rc;
    auto * questions = new Question[40];

    sqlite3_stmt * st = nullptr;
    rc = sqlite3_prepare_v2(db, "SELECT * FROM `questions` ORDER BY random() LIMIT 40", -1, &st, nullptr);
    if (rc != SQLITE_OK)
        return nullptr;

    int i = 0, num;
    rc = sqlite3_step(st);

    while (rc != SQLITE_DONE && rc != SQLITE_OK && i < 40)
    {
        questions[i].id = sqlite3_column_int(st, 0);
        questions[i].theme = sqlite3_column_int(st, 1);
        questions[i].correct = sqlite3_column_int(st, 7);

        strcpy( questions[i].value, (char *) sqlite3_column_text(st, 2) );

        for (int j = 3; j < 7; j++) 
            strcpy( questions[i].ans[j-3], (char *) sqlite3_column_text(st, j) );

        rc = sqlite3_step(st);
        i++;
    }

    if (i != 40) {
        delete(questions);
        return nullptr;
    } else {
        return questions;        
    }

}

int db_set_mark(int user_id, int theme, int mark)
{
    int rc;
    char * value = nullptr;
    sqlite3_stmt * st = nullptr;

    value = db_get_theme_by_id(theme);

    char query[MAX_LEN];
    strcpy(query, "UPDATE `marks` SET ");
    strcat(query, value);
    strcat(query, " = ? WHERE user_id = ?");

    rc = sqlite3_prepare_v2(db, query, -1, &st, nullptr);
    sqlite3_bind_int( st, 1, mark );
    sqlite3_bind_int( st, 2, user_id );

    if (rc != SQLITE_OK)
        return -1;

    rc= sqlite3_step(st);
    if (rc != SQLITE_DONE && rc != SQLITE_OK)
        return -1;

    // only 1 row must be affected
    if (sqlite3_changes(db) != 1)
        return -1;

    return SQLITE_OK;
}

char * db_get_theme_by_id(int index)
{
    switch(index)
    {
        case 0:  return strdup("loops");
        case 1:  return strdup("arrays");
        case 2:  return strdup("strings");
        case 3:  return strdup("recursion");
        case 4:  return strdup("structs");
        case 5:  return strdup("files");
        case 6:  return strdup("pointers");
        case 7:  return strdup("dynamic");
        case 8:  return strdup("average");
        case 9:  return strdup("final");
        default:  return strdup("loops");
    }
}

int db_update_question(Question question)
{

    int rc;
    sqlite3_stmt * st = nullptr;
    
    rc = sqlite3_prepare_v2(db, "UPDATE `questions` SET theme = ?, value = ?, ans1 = ?, ans2 = ?, ans3 = ?, ans4 = ?, correct = ? WHERE id = ?", -1, &st, nullptr);
    sqlite3_bind_int( st, 1, question.theme);
    sqlite3_bind_text( st, 2, question.value, -1, SQLITE_STATIC);
    sqlite3_bind_text( st, 3, question.ans[0], -1, SQLITE_STATIC);
    sqlite3_bind_text( st, 4, question.ans[1], -1, SQLITE_STATIC);
    sqlite3_bind_text( st, 5, question.ans[2], -1, SQLITE_STATIC);
    sqlite3_bind_text( st, 6, question.ans[3], -1, SQLITE_STATIC);
    sqlite3_bind_int( st, 7, question.correct );
    sqlite3_bind_int( st, 8, question.id );

    if (rc != SQLITE_OK)
        return -1;

    rc= sqlite3_step(st);
    if (rc != SQLITE_DONE && rc != SQLITE_OK)
        return -1;

    // only 1 row must be affected
    if (sqlite3_changes(db) != 1)
        return -1;

    return SQLITE_OK;
}

User * db_get_users(int * size)
{
    sqlite3_stmt * st = nullptr;
    *size = 0; // by default
    
    // get number of users
    int rc = sqlite3_prepare_v2(db, "SELECT count(*) FROM `users` WHERE `admin` = 0;", -1, &st, nullptr);

    if (rc != SQLITE_OK)
        return nullptr;
    rc = sqlite3_step(st);
    if (rc != SQLITE_DONE && rc != SQLITE_ROW)
        return nullptr;

    int n = sqlite3_column_int(st, 0);

    if (n <= 0)
        return nullptr;

    *size = n;
    auto users = new User[n];

    rc = sqlite3_prepare_v2(db, "SELECT * FROM `users` WHERE `admin` = 0;", -1, &st, nullptr);
    if (rc != SQLITE_OK)
        return nullptr;

    int i = 0, num;
    rc = sqlite3_step(st);

    while (rc != SQLITE_DONE && rc != SQLITE_OK)
    {
        users[i].id = sqlite3_column_int(st, 0);
        users[i].admin = sqlite3_column_int(st, 5) != 0;

        strcpy(users[i].login, (char *) sqlite3_column_text(st, 1));
        // skip password column
        strcpy( users[i].first_name, (char *) sqlite3_column_text(st, 3) );
        strcpy( users[i].last_name, (char *) sqlite3_column_text(st, 4) );

        rc = sqlite3_step(st);
        i++;
    }

    return users;
}

User * db_get_users_sorted(int * size, int by, int desc)
{
    sqlite3_stmt * st = nullptr;
    char *temp = nullptr;
    *size = 0; // by default

    // get number of users
    int rc = sqlite3_prepare_v2(db, "SELECT count(*) FROM `users` WHERE `admin` = 0;", -1, &st, nullptr);

    if (rc != SQLITE_OK)
        return nullptr;
    rc = sqlite3_step(st);
    if (rc != SQLITE_DONE && rc != SQLITE_ROW)
        return nullptr;

    int n = sqlite3_column_int(st, 0);

    if (n <= 0)
        return nullptr;

    *size = n;
    auto users = new User[n];

    // build a query with some kostyl
    char query[512] = "SELECT users.* FROM `users` as users JOIN `marks` AS m ON m.user_id = users.id AND `admin` = 0 ORDER BY m."; // FUCK YEAH!
    strcat(query, (temp = db_get_theme_by_id(by)));
    free(temp);
    if (desc)
        strcat(query, " DESC;");

    rc = sqlite3_prepare_v2(db, query, -1, &st, nullptr);
    if (rc != SQLITE_OK)
        return nullptr;

    int i = 0, num;
    rc = sqlite3_step(st);

    while (rc != SQLITE_DONE && rc != SQLITE_OK)
    {
        num = sqlite3_column_int(st, 0);
        users[i].id = num;

        strcpy(users[i].login, (char *) sqlite3_column_text(st, 1));
        // skip password column
        strcpy(users[i].first_name, (char *) sqlite3_column_text(st, 3));
        strcpy(users[i].last_name, (char *) sqlite3_column_text(st, 4));

        num = sqlite3_column_int(st, 5);
        users[i].admin = num != 0;

        rc = sqlite3_step(st);
        i++;
    }

    return users;
}

int db_grant_admin(int id)
{
    sqlite3_stmt * st = nullptr;

    // get number of users
    int rc = sqlite3_prepare_v2(db, "UPDATE `users` SET admin=1 WHERE id=?", -1, &st, nullptr);
    if (rc != SQLITE_OK)
        return -1;
    rc = sqlite3_bind_int(st, 1, id);
    if (rc != SQLITE_OK)
        return -1;

    rc = sqlite3_step(st);
    if (rc != SQLITE_DONE && rc != SQLITE_ROW)
        return -1;

    return SQLITE_OK;
}

int db_update_user(User user, char * password)
{
    int rc;
    sqlite3_stmt * st = nullptr;

    rc = sqlite3_prepare_v2(db, "UPDATE `users` SET login = ?, pass = ?, first_name = ?, last_name = ?, admin = ? WHERE id = ?", -1, &st, nullptr);
    sqlite3_bind_text( st, 1, user.login, -1,SQLITE_STATIC);
    sqlite3_bind_text( st, 2, password, -1,SQLITE_STATIC);
    sqlite3_bind_text( st, 3, user.first_name, -1,SQLITE_STATIC);
    sqlite3_bind_text( st, 4, user.last_name, -1,SQLITE_STATIC);
    sqlite3_bind_int( st, 5, (int)user.admin);
    sqlite3_bind_int( st, 6, user.id);

    if (rc != SQLITE_OK)
        return -1;

    rc= sqlite3_step(st);
    if (rc != SQLITE_DONE && rc != SQLITE_OK)
        return -1;

    // only 1 row must be affected
    if (sqlite3_changes(db) != 1)
        return -1;

    return SQLITE_OK;
}

int db_get_id_by_login(const char * login)
{
    int rc;
    sqlite3_stmt * st = nullptr;

    rc = sqlite3_prepare_v2(db, "SELECT `id` FROM `users` WHERE `login` = ? LIMIT 1;", -1, &st, nullptr);
    sqlite3_bind_text( st, 1, login, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK)
        return -1;

    rc= sqlite3_step(st);
    if (rc != SQLITE_DONE && rc != SQLITE_OK && rc != SQLITE_ROW)
        return -1;

    int id = sqlite3_column_int(st, 0);

    return id;
}
