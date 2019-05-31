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

#include "../headers/tests_main_header.h"

// Questions
int delete_the_question() {

    /* Initializing variables */
	int id, size, j, topic;
	struct Question *question = nullptr;

	/* I/O flow */
    while (1) {
        if ((topic = menu_topic()) == -2) {
            ungetc('\n', stdin);
            return 0;
        } else if (topic == -1) {
            ungetc('\n', stdin);
            return -1;
        }

        if ((question = db_get_questions(&size, topic)) != nullptr) {
            for (j = 0; j < size; ++j) {
                printf("|                                                            |\n");
                printf("|  >> Question [%3d]:                                        |\n", question[j].id);
                printf("|                                                            |\n");
                fflush(stdout);
                print_q_correct(question[j].value);
                printf("\n|                                                            |\n");
                prt_ln();
            }

            delete question;

            do {
                printf("| Type the id of question you want to delete: ");
                scanf("%d", &id);
            } while (id < 0);

            if ((db_delete_question(id)) == -1) {
                printf("| Error! Couldn't delete question!                           |\n");
                ungetc('\n', stdin);
                return 0;
            } else {
                break;
            }

        } else {
            printf("Error! Couldn't get questions!\n");
            ungetc('\n', stdin);
            return 0;
        }
    }

    /* Returning value */
    return 1;
}
int add_a_question() {

    /* Initializing variables */
    struct Question quest = {};

    /* I/O flow */
    while (1) {
        quest.theme = menu_topic();
        if (quest.theme == -2) {
            ungetc('\n', stdin);
            return 0;
        } else if (quest.theme == -1) {
            ungetc('\n', stdin);
            return -1;
        }

        printf("| Type question text:                                        |\n");
        fgets(quest.value, MAX_LEN, stdin);
        *(quest.value + strlen(quest.value) - 1) = '\0';
        prt_ln();
        printf("| Type answers:                                              |\n");
        prt_ln();
        printf("| 1) ");
        fgets(quest.ans[0], MAX_LEN, stdin);
        *(quest.ans[0] + strlen(quest.ans[0]) - 1) = '\0';
        printf("| 2) ");
        fgets(quest.ans[1], MAX_LEN, stdin);
        *(quest.ans[1] + strlen(quest.ans[2]) - 1) = '\0';
        printf("| 3) ");
        fgets(quest.ans[2], MAX_LEN, stdin);
        *(quest.ans[2] + strlen(quest.ans[2]) - 1) = '\0';
        printf("| 4) ");
        fgets(quest.ans[3], MAX_LEN, stdin);
        *(quest.ans[3] + strlen(quest.ans[3]) - 1) = '\0';
        prt_ln();

        printf("| Type the number of the correct answer: ");
        scanf("%d", &quest.correct);
        --quest.correct;

        if ((db_add_question(quest)) == -1) {
            printf("| Error! Couldn't add question!                              |\n");
            ungetc('\n', stdin);
            return 0;
        } else {
            break;
        }
    }

	/* Returning value */
	return 1;
}

int menu_change() {

    /* Initializing variables */
    int func, junk, n = 0;

    /* I/O flow */
    while (1) {
        printf(" ------------------------------------------------------------\n"
"|                                                            |\n"
"|                    >> Teacher's mode <<                    |\n"
"|                                                            |\n"
"|  >> What do you want to change?                            |\n"
"|                                                            |\n"
"|       1) Topic                                             |\n"
"|       2) Question text                                     |\n"
"|       3) Answers                                           |\n"
"|       4) Correct answer                                    |\n"
"|                                                            |\n"
"|       >> Type \"back\" to go to the previous menu <<         |\n"
"|       >> Type \"quit\" to terminate this program <<          |\n"
"|                                                            |\n");
        printf("| Answer: ");
        func = getchar();
        prt_ln();
        if (isdigit(func) && func >= '1' && func <= '4') {
            func -= '0';
            if ((junk = getchar()) != '\n') {
                while ((junk = getchar()) != '\n')
                    ;
                no_cmd();
                continue;
            }

            return func;

        } else if (func == 'q') {
            if (quit_m()) {
                return -1;
            } else {
                continue;
            }
        } else if (func == 'b') {
            if (back_m()) {
                return -2;
            } else {
                continue;
            }
        } else {
            no_cmd();
            if (func != '\n') {
                while ((junk = getchar()) != '\n')
                    ;
            }
            continue;
        }
    }
}

int change_the_question() {

    /* Initializing variables */
    int id, size, j, sign, topic;
    struct Question *question = nullptr;
    struct Question quest = {};

    /* I/O flow */

    while (1) {
        if ((topic = menu_topic()) == -2) {
            ungetc('\n', stdin);
            return 0;
        } else if (topic == -1) {
            ungetc('\n', stdin);
            return -1;
        }

        if ((question = db_get_questions(&size, topic)) != nullptr) {
            for (j = 0; j < size; ++j) {
                printf("|                                                            |\n");
                printf("|  >> Question [%3d]:                                        |\n", question[j].id);
                printf("|                                                            |\n");
                fflush(stdout);
                print_q_correct(question[j].value);
                printf("\n|                                                            |\n");
                prt_ln();
            }

            delete question;

            printf("| Type the id of the question you want to change: ");
            do {
                scanf("%d", &id);
            } while (!(quest = db_get_question_by_id(id)).id);

            prt_ln();

            while (getchar() != '\n')
                ;

            if ((sign = menu_change()) == -2) {
                continue;
            } else if (sign == -1) {
                ungetc('\n', stdin);
                return -1;
            }

            switch (sign) {
                case 1:
                    printf("| Type topic: ");
                    scanf("%d", &quest.theme);
                    break;
                case 2:
                    printf("| Type question text: ");
                    fgets(quest.value, MAX_LEN, stdin);
                    *(quest.value + strlen(quest.value) - 1) = '\0';
                    break;
                case 3:
                    printf("| Type answers:                                              |\n");
                    prt_ln();
                    printf("| 1) ");
                    fgets(quest.ans[0], MAX_LEN, stdin);
                    *(quest.ans[0] + strlen(quest.ans[0]) - 1) = '\0';
                    printf("| 2) ");
                    fgets(quest.ans[1], MAX_LEN, stdin);
                    *(quest.ans[1] + strlen(quest.ans[1]) - 1) = '\0';
                    printf("| 3) ");
                    fgets(quest.ans[2], MAX_LEN, stdin);
                    *(quest.ans[2] + strlen(quest.ans[2]) - 1) = '\0';
                    printf("| 4) ");
                    fgets(quest.ans[3], MAX_LEN, stdin);
                    *(quest.ans[3] + strlen(quest.ans[3]) - 1) = '\0';
                    break;
                case 4:
                    do {
                        printf("| Type the number of the correct answer: ");
                        scanf("%d", &quest.correct);
                        --quest.correct;
                    } while (quest.correct < 0 || quest.correct > 3);
                    break;
                default:
                    break;
            }

            if (db_update_question(quest) == -1) {
                printf("| Error! Couldn't update question!                           |\n");
                ungetc('\n', stdin);
                return 0;
            } else {
                break;
            }
        } else {
            printf("| Error! Couldn't get questions!                             |\n");
            ungetc('\n', stdin);
            return 1;
        }
    }

    if (sign != 4) {
        ungetc('\n', stdin);
    }

    /* Final output */
    prt_ln();

    /* Returning value */
    return 0;
}

// Students
int delete_student_account() {

    /* Initializing variables */
	int id, size = 0;
	struct User us;
	struct User *user = nullptr;

	/* Main part */
	while (1) {
        if ((user = db_get_users(&size)) != nullptr) {
            prt_ln();
            for (int i = 0; i < size; ++i) {
                //std::cout << "id = " << user[i].id << "; Student: " << user[i].first_name << user[i].last_name << std::endl;
                printf("|                                                            |\n");
                printf("|  >> Student [%3d]:                                         |\n", user[i].id);
                printf("|                                                            |\n");
                printf("|    %s %s\n", user[i].first_name, user[i].last_name);
                printf("|                                                            |\n");
                prt_ln();
            }
            delete user;

            do {
                printf("| Type the id of the student you want to delete: ");
                scanf("%d", &id);
            } while (!(us = db_get_user(id)).id && us.admin);

            if (db_delete_user(id) == -1) {
                printf("| Error! Couldn't delete student!                            |\n");
                continue;
            } else {
                while (getchar() != '\n')
                    ;
                break;
            }

        } else {
            printf("| Error! Couldn't get students list!                         |\n");
            return 0;
        }
    }
}

int to_add_a_new_account_for_a_student() {

    /* Initializing variables */
	struct User us = {};
	char password[MAX_LEN], pass_2[MAX_LEN];

	/* Main part */
    while (1) {
        printf("| Type first name: ");
        fgets(us.first_name, MAX_LEN, stdin);
        *(us.first_name + (strlen(us.first_name) - 1)) = '\0';
        printf("| Type last name: ");
        fgets(us.last_name, MAX_LEN, stdin);
        *(us.last_name + (strlen(us.last_name) - 1)) = '\0';
        printf("| Type login: ");
        fgets(us.login, MAX_LEN, stdin);
        *(us.login + (strlen(us.login) - 1)) = '\0';

pass_type:
        printf("| Type password: ");
        fgets(password, MAX_LEN, stdin);
        *(password + (strlen(password) - 1)) = '\0';
        printf("| Type password again: ");
        fgets(pass_2, MAX_LEN, stdin);
        *(pass_2 + (strlen(pass_2) - 1)) = '\0';

        prt_ln();

        if (!strcmp(password, pass_2)) {
            if (field_check_teacher(password) && field_check_teacher(us.first_name) &&
            field_check_teacher(us.last_name) && field_check_teacher(us.login)) {
                if (db_get_id_by_login(us.login) > 0) {
                    printf("| Error! User with that login already exists!                |\n");
                    return 0;
                } else {
                    if (db_add_user(us, password) == -1) {
                        printf("| Error! Couldn't add user!                                  |\n");
                        return 0;
                    } else {
                        break;
                    }
                }
            } else {
                printf("| Error! Bad characters in fields!                           |\n");
                prt_ln();
                continue;
            }
        } else {
            printf("| Error! Passwords mismatch!                                 |\n");
            prt_ln();
            goto pass_type;
        }

    }

    /* Returning value */
    return 1;
}

double get_mean(int id) {

    /* Initializing variables */
    int counter = 0;
    struct Marks mks;
    double mean = 0.0;

    /* Main part */
    mks = db_get_user_marks(id);
    for (int i = 0; i < 10; ++i) {
        if (i == 8) {
            continue;
        }
        if (mks.values[i] >= 2 && mks.values[i] <= 5) {
            mean += mks.values[i];
            ++counter;
        }
    }
    if (counter == 0) {
        mean = 0.0;
    } else {
        mean /= counter;
    }

    /* Returning value */
    return mean;
}

int to_see_the_change_of_a_students_progress() {

    /* Initializing variables */
    int size = 0, id;
    struct User *user = nullptr;
    struct User us = {};
    struct Marks mark = {};

    /* Main part */
    if ((user = db_get_users(&size)) != nullptr) {
        prt_ln();
        for (int i = 0; i < size; ++i) {
            //std::cout << "id = " << user[i].id << "; Student: " << user[i].first_name << user[i].last_name << std::endl;
            printf("|                                                            |\n");
            printf("|  >> Student [%3d]:                                         |\n", user[i].id);
            printf("|                                                            |\n");
            printf("|    %s %s\n", user[i].first_name, user[i].last_name);
            printf("|                                                            |\n");
            prt_ln();
        }
        delete user;

        do {
            printf("| Type the id of the student whose progress you want to see: ");
            scanf("%d", &id);
        } while (!(us = db_get_user(id)).id && us.admin);

        prt_ln();
        if ((mark = db_get_user_marks(id)).user_id) {


            printf("|                                                            |\n");
            printf("|  >> Student [%3d]:                                         |\n", us.id);
            printf("|                                                            |\n");
            printf("|    %s %s\n", us.first_name, us.last_name);
            printf("|                                                            |\n");
            printf("|       1) Loops: %d                                          |\n", mark.values[0]);
            printf("|       2) Arrays: %d                                         |\n", mark.values[1]);
            printf("|       3) Strings: %d                                        |\n", mark.values[2]);
            printf("|       4) Recursion: %d                                      |\n", mark.values[3]);
            printf("|       5) Structures: %d                                     |\n", mark.values[4]);
            printf("|       6) Files: %d                                          |\n", mark.values[5]);
            printf("|       7) Pointers and addresses: %d                         |\n", mark.values[6]);
            printf("|       8) Dynamic memory: %d                                 |\n", mark.values[7]);
            printf("|                                                            |\n");
            printf("|       >> Final test: %d                                     |\n", mark.values[9]);
            printf("|       >> Mean: %6.3lf\n", get_mean(id));
            printf("|                                                            |\n");
            prt_ln();
        } else {
            printf("| Error! Couldn't get student's marks!                       |\n");
            return 0;
        }
    } else {
        printf("| Error! Couldn't get students list!                         |\n");
        return 0;
    }

    while (getchar() != '\n')
        ;

    /* Returning value */
    return 1;
}

// Results
int view_scores_on_all_topics() {

    /* Initializing variables */
	int id, size = 0, i;
	struct User *user = nullptr;
	struct Marks mark = {};

	/* Main part */
	prt_ln();
	if ((user = db_get_users(&size)) != nullptr) {
		for (i = 0; i < size; ++i) {
            if ((mark = db_get_user_marks(user[i].id)).user_id) {
                printf("|                                                            |\n");
                printf("|  >> Student [%3d]:                                         |\n", user[i].id);
                printf("|                                                            |\n");
                printf("|    %s %s\n", user[i].first_name, user[i].last_name);
                printf("|                                                            |\n");
                printf("|       1) Loops: %d                                          |\n", mark.values[0]);
                printf("|       2) Arrays: %d                                         |\n", mark.values[1]);
                printf("|       3) Strings: %d                                        |\n", mark.values[2]);
                printf("|       4) Recursion: %d                                      |\n", mark.values[3]);
                printf("|       5) Structures: %d                                     |\n", mark.values[4]);
                printf("|       6) Files: %d                                          |\n", mark.values[5]);
                printf("|       7) Pointers and addresses: %d                         |\n", mark.values[6]);
                printf("|       8) Dynamic memory: %d                                 |\n", mark.values[7]);
                printf("|                                                            |\n");
                prt_ln();
            } else {
                prt_ln();
                printf("| Error! Couldn't get student's marks!                       |\n");
                return 0;
            }
		}
	} else {

	}

	/* Returning value */
    return 1;
}

int menu_how_to_sort() {

    /* Initializing variables */
    int sign, junk, n;

    /* I/O flow */
    while (1) {
        printf(" ------------------------------------------------------------\n"
"|                                                            |\n"
"|                     >> Teacher's mode <<                   |\n"
"|                                                            |\n"
"|  >> Choose sorting type:                                   |\n"
"|                                                            |\n"
"|       1) In ascending order                                |\n"
"|       2) In descending order                               |\n"
"|       3) Show students with a score of \"5\"                 |\n"
"|       4) Show students with a score of \"4\"                 |\n"
"|       5) Show students with a score of \"3\"                 |\n"
"|       6) Show students with a score of \"2\"                 |\n"
"|                                                            |\n"
"|       >> Type \"back\" to go to the previous menu <<         |\n"
"|       >> Type \"quit\" to terminate this program <<          |\n"
"|                                                            |\n");
        printf("| Answer: ");
        sign = getchar();
        prt_ln();
        if (isdigit(sign) && sign >= '1' && sign <= '6') {
            sign -= '0';
            if ((junk = getchar()) != '\n') {
                while ((junk = getchar()) != '\n')
                    ;
                no_cmd();
                continue;
            }

            return sign;

        } else if (sign == 'q') {
            if (quit_m()) {
                return -1;
            } else {
                continue;
            }
        } else if (sign == 'b') {
            if (back_m()) {
                return 0;
            } else {
                continue;
            }
        } else {
            no_cmd();
            while ((junk = getchar()) != '\n')
                ;
            continue;
        }
    }
}

int view_estimates_on_a_specific_topic()
{
	int size = 0, desc, by, sort;
	struct User *user = nullptr;
	struct Marks mark = {};
	char *theme = nullptr;

	while (1) {
        if ((by = menu_topic()) == -2) {
            return 0;
        } else if (by == -1) {
            return -1;
        }

        if (!(sort = menu_how_to_sort())) {
            continue;
        } else if (sort == -1) {
            return -1;
        }

        switch (sort) {
            case 1:
                desc = 0;
                if ((user = db_get_users_sorted(&size, by, desc)) != nullptr) {
                    for (int i = 0; i < size; i++) {
                        if ((mark = db_get_user_marks(user[i].id)).user_id) {
                            printf("|                                                            |\n");
                            printf("|  >> Student [%3d]:                                         |\n", user[i].id);
                            printf("|                                                            |\n");
                            printf("|    %s %s\n", user[i].first_name, user[i].last_name);
                            printf("|                                                            |\n");
                            printf("|       >> %s: %d\n", theme = db_get_theme_by_id(by), mark.values[by]);
                            printf("|                                                            |\n");
                            prt_ln();
                            free(theme);
                        } else {
                            printf("| Error! Couldn't get users marks!                           |\n");
                            return 0;
                        }
                    }

                    delete user;
                } else {
                    printf("| Error! Couldn't get users!                                 |\n");
                    return 0;
                }

                break;
            case 2:
                desc = 1;
                if ((user = db_get_users_sorted(&size, by, desc)) != nullptr) {
                    for (int i = 0; i < size; i++) {
                        if ((mark = db_get_user_marks(user[i].id)).user_id) {
                            printf("|                                                            |\n");
                            printf("|  >> Student [%3d]:                                         |\n", user[i].id);
                            printf("|                                                            |\n");
                            printf("|    %s %s\n", user[i].first_name, user[i].last_name);
                            printf("|                                                            |\n");
                            printf("|       >> %s: %d\n", theme = db_get_theme_by_id(by), mark.values[by]);
                            printf("|                                                            |\n");
                            free(theme);
                            prt_ln();
                        } else {
                            printf("| Error! Couldn't get users marks!                           |\n");
                            return 0;
                        }
                    }

                    delete user;
                } else {
                    printf("| Error! Couldn't get users!                                 |\n");
                    return 0;
                }
                break;
            case 3:
                if ((user = db_get_users_sorted(&size, by, 1)) != nullptr) {
                    for (int i = 0; i < size; i++) {
                        if ((mark = db_get_user_marks(user[i].id)).user_id) {
                            if (mark.values[by] == 5) {
                                printf("|                                                            |\n");
                                printf("|  >> Student [%3d]:                                         |\n", user[i].id);
                                printf("|                                                            |\n");
                                printf("|    %s %s\n", user[i].first_name, user[i].last_name);
                                printf("|                                                            |\n");
                                printf("|       >> %s: %d\n", theme = db_get_theme_by_id(by), mark.values[by]);
                                printf("|                                                            |\n");
                                free(theme);
                                prt_ln();
                            }
                        } else {
                            printf("| Error! Couldn't get users marks!                           |\n");
                            return 0;
                        }
                    }

                    delete user;
                } else {
                    printf("| Error! Couldn't get users!                                 |\n");
                    return 0;
                }
                break;
            case 4:
                if ((user = db_get_users_sorted(&size, by, 1)) != nullptr) {
                    for (int i = 0; i < size; i++) {
                        if ((mark = db_get_user_marks(user[i].id)).user_id) {
                            if (mark.values[by] == 4) {
                                printf("|                                                            |\n");
                                printf("|  >> Student [%3d]:                                         |\n", user[i].id);
                                printf("|                                                            |\n");
                                printf("|    %s %s\n", user[i].first_name, user[i].last_name);
                                printf("|                                                            |\n");
                                printf("|       >> %s: %d\n", theme = db_get_theme_by_id(by), mark.values[by]);
                                printf("|                                                            |\n");
                                free(theme);
                                prt_ln();
                            }
                        } else {
                            printf("| Error! Couldn't get users marks!                           |\n");
                            return 0;
                        }
                    }

                    delete user;
                } else {
                    printf("| Error! Couldn't get users!                                 |\n");
                    return 0;
                }
                break;
            case 5:
                if ((user = db_get_users_sorted(&size, by, 1)) != nullptr) {
                    for (int i = 0; i < size; i++) {
                        if ((mark = db_get_user_marks(user[i].id)).user_id) {
                            if (mark.values[by] == 3) {
                                printf("|                                                            |\n");
                                printf("|  >> Student [%3d]:                                         |\n", user[i].id);
                                printf("|                                                            |\n");
                                printf("|    %s %s\n", user[i].first_name, user[i].last_name);
                                printf("|                                                            |\n");
                                printf("|       >> %s: %d\n", theme = db_get_theme_by_id(by), mark.values[by]);
                                printf("|                                                            |\n");
                                free(theme);
                                prt_ln();
                            }
                        } else {
                            printf("| Error! Couldn't get users marks!                           |\n");
                            return 0;
                        }
                    }

                    delete user;
                } else {
                    printf("| Error! Couldn't get users!                                 |\n");
                    return 0;
                }
                break;
            case 6:
                if ((user = db_get_users_sorted(&size, by, 1)) != nullptr) {
                    for (int i = 0; i < size; i++) {
                        if ((mark = db_get_user_marks(user[i].id)).user_id) {
                            if (mark.values[by] == 2) {
                                printf("|                                                            |\n");
                                printf("|  >> Student [%3d]:                                         |\n", user[i].id);
                                printf("|                                                            |\n");
                                printf("|    %s %s\n", user[i].first_name, user[i].last_name);
                                printf("|                                                            |\n");
                                printf("|       >> %s: %d\n", theme = db_get_theme_by_id(by), mark.values[by]);
                                printf("|                                                            |\n");
                                free(theme);
                                prt_ln();
                            }
                        } else {
                            printf("| Error! Couldn't get users marks!                           |\n");
                            return 0;
                        }
                    }

                    delete user;
                } else {
                    printf("| Error! Couldn't get users!                                 |\n");
                    return 0;
                }
                break;
            default:
                break;
        }

        break;
    }

	/* Returning value */
    return 1;
}
int view_scores_for_the_final_test() {

    /* Initializing variables */
	int size, i;
	struct User *user = nullptr;
	struct Marks mark = {};

	/* Main part */
    if ((user = db_get_users_sorted(&size, 9, 1)) != nullptr) {
        for (i = 0; i < size; ++i) {
            if ((mark = db_get_user_marks(user[i].id)).user_id) {
                    printf("|                                                            |\n");
                    printf("|  >> Student [%3d]:                                         |\n", user[i].id);
                    printf("|                                                            |\n");
                    printf("|    %s %s\n", user[i].first_name, user[i].last_name);
                    printf("|                                                            |\n");
                    printf("|       >> Final test: %d                                     |\n", mark.values[9]);
                    printf("|                                                            |\n");
                    prt_ln();
            } else {
                printf("| Error! Couldn't get users marks!                           |\n");
                return 0;
            }
        }

        delete user;
    } else {
        printf("| Error! Couldn't get users!                                 |\n");
        return 0;
    }

	/* Returning value */
	return 1;
}

int view_the_average_score() {

    /* Initializing variables */
	int size = 0, i;
	struct User *user = nullptr;
	struct Marks mark = {};

	/* Main part */
	if ((user = db_get_users(&size))) {
        for (i = 0; i < size; ++i) {
            if ((mark = db_get_user_marks(user[i].id)).user_id) {
                printf("|                                                            |\n");
                printf("|  >> Student [%3d]:                                         |\n", user[i].id);
                printf("|                                                            |\n");
                printf("|    %s %s\n", user[i].first_name, user[i].last_name);
                printf("|                                                            |\n");
                printf("|       >> Mean: %6.3lf\n", get_mean(mark.user_id));
                printf("|                                                            |\n");
                prt_ln();
            } else {
                printf("| Error! Couldn't get users marks!                           |\n");
                return 0;
            }
        }

        delete user;
    } else {
        printf("| Error! Couldn't get users!                                 |\n");
        return 0;
    }

	/* Returning value */
    return 1;
}