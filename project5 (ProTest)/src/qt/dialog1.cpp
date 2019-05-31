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

#include "dialog1.h"
#include "../build-qt-Desktop-Debug/ui_dialog1.h"
#include "mainwindow.h"
#include "mainwindow_teach.h"

extern sqlite3 *db;

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    /* Main part */
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::SetLogin(class QString str) {

    /* Initializing variables */
    ui->lineEditLogin->setText(str);
}

void Dialog1::SetPass(class QString str) {

    /* Initializing variables */
    ui->lineEditPass->setText(str);
    ui->lineEditPass->setStyleSheet("");
    ui->lineEditPass_2->setStyleSheet("");
}

void Dialog1::SignUp() {

    /* Main part */
    ui->label->setText("Sign up");
    ui->pushSignUp->setText("Sign up");
    ui->radioTeacher->setCheckable(true);
    ui->radioStudent->setChecked(false);
    ui->radioTeacher->setChecked(false);
    Dialog1::setWindowTitle("Sign up");
}

void Dialog1::AddStudent() {

    /* Main part */
    ui->label->setText("Add student");
    ui->pushSignUp->setText("Add");
    ui->radioTeacher->setCheckable(false);
//    ui->radioTeacher->setVisible(false);
    ui->radioTeacher->setEnabled(false);
    ui->radioStudent->setChecked(true);
    Dialog1::setWindowTitle("Add student");
}

int Dialog1::field_check(char *text) {

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

void Dialog1::on_lineEditPass_2_textChanged(const QString &arg1)
{
    /* Main part */
    if (arg1 != "" && ui->lineEditFN->text() != "" && ui->lineEditLN->text() != "" &&
            ui->lineEditPass->text() != "" && ui->lineEditLogin->text() != "" &&
            (ui->radioStudent->isChecked() || ui->radioTeacher->isChecked())) {
        ui->pushSignUp->setEnabled(true);
    } else {
        ui->pushSignUp->setEnabled(false);
    }

    if (ui->lineEditPass->text() != "") {
        if (arg1 != ui->lineEditPass->text()) {
            ui->lineEditPass->setStyleSheet("QLineEdit {background: rgb(255, 255, 0); selection-background-color: rgb(250, 150, 0); }");
            ui->lineEditPass_2->setStyleSheet("QLineEdit {background: rgb(255, 255, 0); selection-background-color: rgb(250, 150, 0); }");
        } else {
            ui->lineEditPass->setStyleSheet("QLineEdit {background: rgb(150, 255, 0); selection-background-color: rgb(100, 250, 0); }");
            ui->lineEditPass_2->setStyleSheet("QLineEdit {background: rgb(150, 255, 0); selection-background-color: rgb(100, 250, 0); }");
        }
    }

    if (arg1 == "") {
        ui->lineEditPass->setStyleSheet("");
        ui->lineEditPass_2->setStyleSheet("");
    }
}

void Dialog1::on_lineEditPass_2_editingFinished()
{
    /* Main part */
    if (ui->lineEditPass_2->text() != "" && ui->lineEditPass->text() != ""){
        if (ui->lineEditPass_2->text() != ui->lineEditPass->text()) {
            ui->lineEditPass->setStyleSheet("QLineEdit {background: rgb(255, 80, 80); selection-background-color: rgb(255, 0, 0); }");
            ui->lineEditPass_2->setStyleSheet("QLineEdit {background: rgb(255, 80, 80); selection-background-color: rgb(255, 0, 0); }");
        } else {
            ui->lineEditPass->setStyleSheet("QLineEdit {background: rgb(150, 255, 0); selection-background-color: rgb(100, 250, 0); }");
            ui->lineEditPass_2->setStyleSheet("QLineEdit {background: rgb(150, 255, 0); selection-background-color: rgb(100, 250, 0); }");
        }

        if (ui->lineEditPass_2->text() == "") {
            ui->lineEditPass->setStyleSheet("");
            ui->lineEditPass_2->setStyleSheet("");
        }
    }
}

void Dialog1::on_lineEditFN_textChanged(const QString &arg1)
{
    /* Main part */
    if (arg1 != "" && ui->lineEditLN->text() != "" && ui->lineEditLogin->text() != "" &&
            ui->lineEditPass->text() != "" && ui->lineEditPass_2->text() != "" &&
            (ui->radioStudent->isChecked() || ui->radioTeacher->isChecked())) {
        ui->pushSignUp->setEnabled(true);
    } else {
        ui->pushSignUp->setEnabled(false);
    }
}

void Dialog1::on_lineEditLN_textChanged(const QString &arg1)
{
    /* Main part */
    if (arg1 != "" && ui->lineEditFN->text() != "" && ui->lineEditLogin->text() != "" &&
            ui->lineEditPass->text() != "" && ui->lineEditPass_2->text() != "" &&
            (ui->radioStudent->isChecked() || ui->radioTeacher->isChecked())) {
        ui->pushSignUp->setEnabled(true);
    } else {
        ui->pushSignUp->setEnabled(false);
    }
}

void Dialog1::on_lineEditLogin_textChanged(const QString &arg1)
{
    /* Main part */
    if (arg1 != "" && ui->lineEditFN->text() != "" && ui->lineEditLN->text() != "" &&
            ui->lineEditPass->text() != "" && ui->lineEditPass_2->text() != "" &&
            (ui->radioStudent->isChecked() || ui->radioTeacher->isChecked())) {
        ui->pushSignUp->setEnabled(true);
    } else {
        ui->pushSignUp->setEnabled(false);
    }
}

void Dialog1::on_lineEditPass_textChanged(const QString &arg1)
{
    /* Main part */
    if (arg1 != "" && ui->lineEditFN->text() != "" && ui->lineEditLogin->text() != "" &&
            ui->lineEditPass->text() != "" && ui->lineEditPass_2->text() != "" &&
            (ui->radioStudent->isChecked() || ui->radioTeacher->isChecked())) {
        ui->pushSignUp->setEnabled(true);
    } else {
        ui->pushSignUp->setEnabled(false);
    }

    if (ui->lineEditPass_2->text() != "") {
        if (arg1 != ui->lineEditPass_2->text() && ui->lineEditPass_2->text() != "") {
            ui->lineEditPass->setStyleSheet("QLineEdit {background: rgb(255, 255, 0); selection-background-color: rgb(250, 150, 0); }");
            ui->lineEditPass_2->setStyleSheet("QLineEdit {background: rgb(255, 255, 0); selection-background-color: rgb(250, 150, 0); }");
        } else {
            ui->lineEditPass->setStyleSheet("QLineEdit {background: rgb(150, 255, 0); selection-background-color: rgb(100, 250, 0); }");
            ui->lineEditPass_2->setStyleSheet("QLineEdit {background: rgb(150, 255, 0); selection-background-color: rgb(100, 250, 0); }");
        }
    }

    if (arg1 == "") {
        ui->lineEditPass->setStyleSheet("");
        ui->lineEditPass_2->setStyleSheet("");
    }

}

void Dialog1::on_radioStudent_toggled(bool checked)
{
    /* Main part */
    if (ui->lineEditFN->text() != "" && ui->lineEditLN->text() != "" && ui->lineEditLogin->text() != "" &&
            ui->lineEditPass->text() != "" && ui->lineEditPass_2->text() != "" &&
            checked == true) {
        ui->pushSignUp->setEnabled(true);
    } else {
        ui->pushSignUp->setEnabled(false);
    }
}

void Dialog1::on_radioTeacher_toggled(bool checked)
{
    /* Main part */
    if (ui->lineEditFN->text() != "" && ui->lineEditLN->text() != "" && ui->lineEditLogin->text() != "" &&
            ui->lineEditPass->text() != "" && ui->lineEditPass_2->text() != "" &&
            checked == true) {
        ui->pushSignUp->setEnabled(true);
    } else {
        ui->pushSignUp->setEnabled(false);
    }
}

void Dialog1::on_lineEditPass_editingFinished()
{
    /* Main part */
    if (ui->lineEditPass->text() != "" && ui->lineEditPass_2->text() != "") {
        if (ui->lineEditPass_2->text() != ui->lineEditPass->text()) {
            ui->lineEditPass->setStyleSheet("QLineEdit {background: rgb(255, 80, 80); selection-background-color: rgb(255, 0, 0); }");
            ui->lineEditPass_2->setStyleSheet("QLineEdit {background: rgb(255, 80, 80); selection-background-color: rgb(255, 0, 0); }");
        } else {
            ui->lineEditPass->setStyleSheet("QLineEdit {background: rgb(150, 255, 0); selection-background-color: rgb(100, 250, 0); }");
            ui->lineEditPass_2->setStyleSheet("QLineEdit {background: rgb(150, 255, 0); selection-background-color: rgb(100, 250, 0); }");
        }
    }
}

void Dialog1::on_pushSignUp_clicked()
{

    /* Initializing variables */
    char *login, *pass, *fn, *ln;
    int role, id = -1;
    QString Qlogin, Qpass, Q1, Qfn, Qln;
    QByteArray temp_ba;
    QMessageBox::StandardButton reply;
    struct User usr;

    /* Main part */
//    if (db_open(PATH_TO_DB) != -1) {
        if (ui->lineEditPass->text() == ui->lineEditPass_2->text()) {
            Qlogin = ui->lineEditLogin->text();
            temp_ba = Qlogin.toLocal8Bit();
            login = strdup(temp_ba);

            Qpass = ui->lineEditPass->text();
            temp_ba = Qpass.toLocal8Bit();
            pass = strdup(temp_ba);

            Qfn = ui->lineEditFN->text();
            temp_ba = Qfn.toLocal8Bit();
            fn = strdup(temp_ba);

            Qln = ui->lineEditLN->text();
            temp_ba = Qln.toLocal8Bit();
            ln = strdup(temp_ba);

            role = (ui->radioStudent->isChecked()) ? 1 : 2;

            Q1 = "Is that OK?\n\nLogin: " + Qlogin + "\nFirst name: " + Qfn + "\nLast name: " +
                    Qln + "\nRole: " + ((role == 1) ? "Student" : "Teacher");

            reply = QMessageBox::question(this, ui->label->text(), Q1, QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                id = db_get_id_by_login(login);
                if (id > 0) {
                    QMessageBox::critical(this, "Error!", "User with that login already exists!");
                } else {
                    if (Dialog1::field_check(login) && Dialog1::field_check(pass)) {
                        strcpy(usr.login, login);
                        strcpy(usr.first_name, fn);
                        strcpy(usr.last_name, ln);
                        if (role == 1) {
                            id = db_add_user(usr, pass);
                        } else if (role == 2) {
                            id = db_add_admin(usr, pass);
                        }

                        if (id != -1) {
                            /* Forum's code */
                            if (ui->label->text() == "Sign up") {
                                QMessageBox::information(this, "Done!", "Signed up successfully!");
                                QObject *p = this;
                                do
                                {
                                    p = p->parent();
                                } while (p->parent() != nullptr);

                                MainWindow *mw = qobject_cast<MainWindow *>(p);
                                if (!mw)
                                {
                                    // couldnt find main window
                                }
                                else
                                {
                                    mw->SetLogin(Qlogin);
                                    mw->SetPass(Qpass);
                                    mw->show();

                                    this->hide();
                                }
                            } else if (ui->label->text() == "Add student") {
                                QMessageBox::information(this, "Done!", "Student was added successfully!");
                                QObject *p = this;

                                p = p->parent();

                                MainWindow_teach *mwt = qobject_cast<MainWindow_teach *>(p);

                                if (!mwt) {
                                    // couldnt find main window
                                } else {
                                    mwt->refresh_users();
                                    mwt->refresh_table();
                                }
                                this->hide();
                            }
                        } else {
                            QMessageBox::critical(this, "Error!", "Failed to create user!");
                        }
                    } else {
                        QMessageBox::critical(this, "Error!", "Bad characters in login or password!");
                    }

                }
            }

            free(login);
            free(pass);
            free(fn);
            free(ln);
        } else {
            QMessageBox::critical(this, "Error!", "Password mismatch!");
        }
//    } else {
//        QMessageBox::critical(this, "Error!", "Couldn't open database!");
//    }
}

void Dialog1::on_Dialog1_destroyed()
{

    /* Main window */
    db_close();
}
