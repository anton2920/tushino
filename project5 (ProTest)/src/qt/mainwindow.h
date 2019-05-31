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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <QDesktopWidget>
#include <QMessageBox>
#include "dialog1.h"
#include "mainwindow_teach.h"
#include "../headers/tests_main_header.h"
#include "mainwindow_stud.h"

namespace Ui {
class MainWindow;

struct Log_pass {
    char login[MAX_LEN];
    char pass[MAX_LEN];
};

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetLogin(class QString);
    void SetPass(class QString);

private slots:
    void on_pushButtonSignIn_clicked();

    void on_pushButtonSignUp_clicked();

    void on_lineLogin_textChanged(const QString &arg1);

    void on_linePass_textChanged(const QString &arg1);

    void on_MainWindow_destroyed();

private:
    Ui::MainWindow *ui;
    Dialog1 *dialog1;
    MainWindow_teach *mwt;
    MainWindow_stud *mws;
};

#endif // MAINWINDOW_H
