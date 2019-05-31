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

#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <QMessageBox>
#include "../headers/tests_main_header.h"

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();
    void SetLogin(class QString);
    void SetPass(class QString);
    void SignUp();
    void AddStudent();
    int field_check(char *);

private slots:
    void on_lineEditPass_2_textChanged(const QString &arg1);

    void on_lineEditPass_2_editingFinished();

    void on_lineEditFN_textChanged(const QString &arg1);

    void on_lineEditLN_textChanged(const QString &arg1);

    void on_lineEditLogin_textChanged(const QString &arg1);

    void on_lineEditPass_textChanged(const QString &arg1);

    void on_radioStudent_toggled(bool checked);

    void on_radioTeacher_toggled(bool checked);

    void on_lineEditPass_editingFinished();

    void on_pushSignUp_clicked();

    void on_Dialog1_destroyed();

private:
    Ui::Dialog1 *ui;
};

#endif // DIALOG1_H
