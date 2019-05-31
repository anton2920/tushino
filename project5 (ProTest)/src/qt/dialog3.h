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

#ifndef DIALOG3_H
#define DIALOG3_H

#include <QDialog>
#include "../headers/tests_main_header.h"

extern int tt;

namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = nullptr);
    ~Dialog3();
    void select_test_type(int);

private slots:
    void on_pushButton_Loops_clicked();

    void on_pushButton_Arrays_clicked();

    void on_pushButton_Strings_clicked();

    void on_pushButton_Recursion_clicked();

    void on_pushButton_Structures_clicked();

    void on_pushButton_Files_clicked();

    void on_pushButton_Pointers_clicked();

    void on_pushButton_Dyn_Mem_clicked();

    void start(int);

private:
    Ui::Dialog3 *ui;
};

#endif // DIALOG3_H
