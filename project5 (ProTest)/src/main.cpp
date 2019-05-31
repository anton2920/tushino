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

#include "headers/tests_main_header.h"

sqlite3 *db = nullptr;

int main(int argc, char *argv[]) {

    /* Random number stuff */
    srand(time(nullptr));

    /* Locale problems */
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    /* Check for Qt */
#if (HAVE_QT == 1)
    qt_main(argc, argv);
#else

    /* Initializing variables */
    int func;
    char *path = nullptr;

    /* Main part */
    path = secure_getenv("HOME");
    strcat(path, PATH_TO_DB);
    if (db_open(path) == -1) {
        printf("| Error! Couldn't open database                              |\n");
    }

    do {
        func = main_menu();
        if (func == -1) {
            break;
        }
    } while (menu_continue());

    /* Returning value */
    return 0;
#endif
}
