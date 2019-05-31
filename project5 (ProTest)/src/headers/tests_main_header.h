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

#ifndef MAIN_HEADER_TEST
#define MAIN_HEADER_TEST

/* Macros */
#define PATH_TO_DB ("/.local/share/ProTest/data.sqlite")

/* Types */
typedef enum test_type {
    training,
    practice,
    final
} t_type;

/* Include config.h */
#include "config.h"

/* Include general headers */
#if (HAVE_STRING == 1)
    #include <string>
#endif

#if (HAVE_CSTDIO == 1)
    #include <cstdio>
#endif

#if (HAVE_IOSTREAM == 1)
    #include <iostream>
#endif

#if (HAVE_CSTRING == 1)
    #include <cstring>
#endif

#if (HAVE_STDLIB_H == 1)
    #include <stdlib.h>
#endif

#if (HAVE_TIME_H == 1)
    #include <time.h>
#endif

/* Include local headers */
#include "sqlite3.h"
#include "database.h"
#include "teacher_menu.h"
#include "main_menu.h"
#include "student_menu.h"

/* main.cpp */
extern sqlite3 *db;

/* qt_main.cpp */
int qt_main(int, char *[]);

#endif
