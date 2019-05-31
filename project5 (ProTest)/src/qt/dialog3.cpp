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

#include "dialog3.h"
#include "../build-qt-Desktop-Debug/ui_dialog3.h"
#include "mainwindow_stud.h"

int tt = 0;

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);
}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::on_pushButton_Loops_clicked()
{

    /* Main part */
    start(0);
}

void Dialog3::on_pushButton_Arrays_clicked()
{

    /* Main part */
    start(1);
}

void Dialog3::on_pushButton_Strings_clicked()
{

    /* Main part */
    start(2);
}

void Dialog3::on_pushButton_Recursion_clicked()
{

    /* Main part */
    start(3);
}

void Dialog3::on_pushButton_Structures_clicked()
{

    /* Main part */
    start(4);
}

void Dialog3::on_pushButton_Files_clicked()
{

    /* Main part */
    start(5);
}

void Dialog3::on_pushButton_Pointers_clicked()
{

    /* Main part */
    start(6);
}

void Dialog3::on_pushButton_Dyn_Mem_clicked()
{

    /* Main part */
    start(7);
}

void Dialog3::select_test_type(int t) {

    /* Initializing variables */
    extern int tt;
    tt = t;
}

void Dialog3::start(int theme) {

    /* Initializing variables */
    extern int tt;

    /* Main part */
    QObject *p = this;

    p = p->parent();

    MainWindow_stud *mws = qobject_cast<MainWindow_stud *>(p);
    if (!mws)
    {
        // couldnt find main window
    }
    else
    {
        if (tt == 1) {
            mws->practice(theme);
        } else if (!tt) {
            mws->training(theme);
        }

        this->hide();
    }
}
