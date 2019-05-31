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


int student_menu() {

	/* Initializing variables */
	int sign, junk, n,check = 0;
	check = signin();

	/* VarCheck */
	if (!check) {
        return 0;
    }

	/* I/O flow */
	while (1) {
		printf(" ------------------------------------------------------------\n"
			"|                                                            |\n"
			"|                     >> Student's mode <<                   |\n"
			"|                                                            |\n"
			"|  >> Choose a test type:                                    |\n"
			"|                                                            |\n"
			"|       1) Training on a topic                               |\n"
			"|       2) Testing on a topic                                |\n"
			"|       3) Final test                                        |\n"
			"|                                                            |\n"
			"|       >> Type \"back\" to go to the previous menu <<         |\n"
			"|       >> Type \"quit\" to terminate this program <<          |\n"
			"|                                                            |\n");
		printf("| Answer: ");
		sign = getchar();

		if (isdigit(sign) && sign >= '1' && sign <= '3') {
			sign -= '0';
			if ((junk = getchar()) != '\n') {
				while ((junk = getchar()) != '\n')
					;
				no_cmd();
				continue;
			}

			switch (sign) {
			case 1:
			    n = Training();
				break;
			case 2:
			    n = Test(check);
				break;
			case 3:
			    n = FinalTest(check);
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