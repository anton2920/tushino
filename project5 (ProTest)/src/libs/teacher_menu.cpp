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


int edit_questions_teacher()
{
	/* Initializing variables */
	int func, junk, n = 0;

	/* I/O flow */
	while (1) {
		printf(" ------------------------------------------------------------\n"
"|                                                            |\n"
"|                    >> Teacher's mode <<                    |\n"
"|                                                            |\n"
"|  >> Choose action:                                         |\n"
"|                                                            |\n"
"|       1) Delete the question                               |\n"
"|       2) Add a question                                    |\n"
"|       3) Change the question                               |\n"
"|                                                            |\n"
"|       >> Type \"back\" to go to the previous menu <<         |\n"
"|       >> Type \"quit\" to terminate this program <<          |\n"
"|                                                            |\n");
		printf("| Answer: ");
		func = getchar();
		prt_ln();
		if (isdigit(func) && func >= '1' && func <= '3') {
			func -= '0';
			if ((junk = getchar()) != '\n') {
				while ((junk = getchar()) != '\n');
				no_cmd();
				continue;
			}
			switch (func) {
			case 1:
				n = delete_the_question();
				break;
			case 2:
				n = add_a_question();
				break;
			case 3:
				n = change_the_question();
				break;
			default:
				break;
			}

            while ((junk = getchar()) != '\n')
                ;

            if (!n) {
                continue;
            } else if (n == -1) {
                return -1;
            } else {
                return 0;
            }
		}
		else if (func == 'q') {
			if (quit_m()) {
				return -1;
			}
			else {
				continue;
			}
		}
		else if (func == 'b') {
			if (back_m()) {
				return 0;
			}
			else {
				continue;
			}
		}
		else {
			no_cmd();
			if (func != '\n') {
				while ((junk = getchar()) != '\n')
					;
			}
			continue;
		}
	}
}

int working_with_the_list_of_students() {

	/* Initializing variables */
	int sign, junk, n;

	/* I/O flow */
	while (1) {
        printf(" ------------------------------------------------------------\n"
"|                                                            |\n"
"|                    >> Teacher's mode <<                    |\n"
"|                                                            |\n"
"|  >> Choose action:                                         |\n"
"|                                                            |\n"
"|       1) Delete student account                            |\n"
"|       2) Add a new account for a student                   |\n"
"|       3) See the change of a student's progress            |\n"
"|       4) Show the list of students with grades             |\n"
"|                                                            |\n"
"|       >> Type \"back\" to go to the previous menu <<         |\n"
"|       >> Type \"quit\" to terminate this program <<          |\n"
"|                                                            |\n");
		printf("| Answer: ");
		sign = getchar();
		prt_ln();
		if (isdigit(sign) && sign >= '1' && sign <= '4') {
			sign -= '0';
			if ((junk = getchar()) != '\n') {
				while ((junk = getchar()) != '\n')
					;
				no_cmd();
				continue;
			}

			switch (sign) {
			    case 1:
					n = delete_student_account();
					break;
				case 2: 
					n = to_add_a_new_account_for_a_student();
					break;
				case 3: 
					n = to_see_the_change_of_a_students_progress();
					break;
				case 4: 
					n = view_the_list_of_students_with_grades();
					break;
				default:
					break;
				}

            if (!n) {
                continue;
            } else if (n == -1) {
                return -1;
            } else {
                return 0;
            }

		} else if (sign == 'q') {
			if (quit_m()) {
				return -1;
			} else {
				continue;
			}
		} else if (sign == 'b') {
			if (back_m()) {
				return 0;
			}
			else {
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


int view_the_list_of_students_with_grades() {

	/* Initializing variables */
	int sign, junk, n;

	/* I/O flow */
	while (1) {
		printf(" ------------------------------------------------------------\n"
"|                                                            |\n"
"|                    >> Teacher's mode <<                    |\n"
"|                                                            |\n"
"|  >> Choose action:                                         |\n"
"|                                                            |\n"
"|       1) Show scores on all topics                         |\n"
"|       2) Show scores on a specific topic                   |\n"
"|       3) Show scores for the final test                    |\n"
"|       4) Show the average score                            |\n"
"|                                                            |\n"
"|       >> Type \"back\" to go to the previous menu <<         |\n"
"|       >> Type \"quit\" to terminate this program <<          |\n"
"|                                                            |\n");
		printf("| Answer: ");
		sign = getchar();
		prt_ln();
		if (isdigit(sign) && sign >= '1' && sign <= '4') {
			sign -= '0';
			if ((junk = getchar()) != '\n') {
				while ((junk = getchar()) != '\n')
					;
				no_cmd();
				continue;
			}

			switch (sign) {
                case 1:
                    n = view_scores_on_all_topics();
                    break;
                case 2:
                    n = view_estimates_on_a_specific_topic();
                    break;
                case 3:
                    n = view_scores_for_the_final_test();
                    break;
                case 4:
                    n = view_the_average_score();
                    break;
                default:
                    break;
            }

            if (!n) {
                continue;
            } else if (n == -1) {
                return -1;
            } else {
                return 0;
            }

		}
		else if (sign == 'q') {
			if (quit_m()) {
				return -1;
			}
			else {
				continue;
			}
		}
		else if (sign == 'b') {
			if (back_m()) {
				return 0;
			}
			else {
				continue;
			}
		}
		else {
			no_cmd();
			while ((junk = getchar()) != '\n')
				;
			continue;
		}
	}
}
int teacher_menu_0() {

    /* Initializing variables */
    int sign, junk, n;

    /* I/O flow */
    if (!input_teacher()) {
        return 0;
    }
    while (1) {
        printf(" ------------------------------------------------------------\n"
"|                                                            |\n"
"|                     >> Teacher's mode <<                   |\n"
"|                                                            |\n"
"|  >> Choose action:                                         |\n"
"|                                                            |\n"
"|       1) Edit questions                                    |\n"
"|       2) Working with the list of students                 |\n"
"|                                                            |\n"
"|       >> Type \"back\" to go to the previous menu <<         |\n"
"|       >> Type \"quit\" to terminate this program <<          |\n"
"|                                                            |\n");
        printf("| Answer: ");
        sign = getchar();
        prt_ln();
        if (isdigit(sign) && sign >= '1' && sign <= '2') {
            sign -= '0';
            if ((junk = getchar()) != '\n') {
                while ((junk = getchar()) != '\n')
                    ;
                no_cmd();
                continue;
            }
            switch (sign) {
                case 1:
                    n = edit_questions_teacher();
                    break;
                case 2:
                    n = working_with_the_list_of_students();
                    break;
                default:
                    break;
            }

            if (!n) {
                continue;
            } else if (n == -1) {
                return -1;
            } else {
                return 0;
            }

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

int field_check_teacher(char *text) {

	/* Initializing variables */
	int i;
	char ch;

	/* Main part */
	for (i = 0; i < static_cast<int>(strlen(text)); ++i) {
		ch = *(text + i);
		if (ch == ' ' || ch == '\n' || ch == ' ') {
			return 0;
		}
	}

	/* Returning value */
	return 1;
}

int input_teacher()
{

    /* Initializing variables */
    User user = {};
    char password[MAX_LEN], login[MAX_LEN];

    /* I/O flow */
    printf("| Type the username: ");
    fgets(login, MAX_LEN, stdin);
    printf("| Type the password: ");
    fgets(password, MAX_LEN, stdin);

    /* Main part */
    login[strlen(login) - 1] = '\0';
    password[strlen(password) - 1] = '\0';

    if (field_check_teacher(login) && field_check_teacher(password)) {
        user = db_login(login, password);

        if (user.admin && user.id) {
            return 1;
        } else {
            prt_ln();
            printf("| Error! Wrong login or password!                            |\n");
            return 0;
        }
    } else {
        return 0;
    }
}
