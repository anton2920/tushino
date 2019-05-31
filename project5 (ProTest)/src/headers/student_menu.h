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

#ifndef STUDENT_MENU_H
#define STUDENT_MENU_H

#include "../headers/tests_main_header.h"

int signin();
int student_menu();
int menu_topic();
void print_q_correct(const char *);
int get_q_ans(struct Question *, int, int, t_type);

int Training();
int Test(int id);
int FinalTest(int id);

#endif