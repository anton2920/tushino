/*
ProTest — free powerful program for educational tests
Copyright © 2019 Tushino Software LLC

This file is part of ProTest.

ProTest is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

ProTest is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ProTest. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef DB_MAIN_HEADER
#define DB_MAIN_HEADER

#include "sqlite3.h"
#include "sha256.h"

#define MAX_LEN 512

extern sqlite3 *db;

struct User {
    int id;
    bool admin;
    char login[MAX_LEN];
    char first_name[MAX_LEN];
    char last_name[MAX_LEN];
};

struct Question {
    int id;
    int theme;
    char value[MAX_LEN];
    char ans[4][MAX_LEN];
    int correct;
};

struct Marks {
    int user_id;
    int values[10];
};

/**
*   INITIALIZATION
*/

int db_open();
int db_open(const char * name);
void db_close();

/**
*   USERS
*/

User db_login(char * login, char * password);
int db_add_user(User user, char * password);
int db_add_admin(User user, char * password);
int db_grant_admin(int id);
int db_update_user(User user, char * password);
int db_delete_user(int id);
User db_get_user(int id);
int db_get_id_by_login(const char * login);
User * db_get_users(int * size);
User * db_get_users_sorted(int * size, int by, int desc);

/**
*   MARKS
*/

int db_set_mark(int user_id, int theme, int mark);
Marks db_get_user_marks(int user_id);

/**
*   QUESTIONS AND TESTS
*/

Question * db_get_test(int theme);
Question * db_get_final_test();
Question * db_get_questions(int * size);
Question * db_get_questions(int * size, int theme);
Question db_get_question_by_id(int id);

int db_add_question(Question question);
int db_delete_question(int id);
int db_update_question(Question question);

/**
*   UTILITIES
*/

char * db_get_theme_by_id(int index);

#endif
