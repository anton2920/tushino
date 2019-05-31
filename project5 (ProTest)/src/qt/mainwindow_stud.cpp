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

#include "mainwindow_stud.h"
#include "../build-qt-Desktop-Debug/ui_mainwindow_stud.h"
#include "../headers/tests_main_header.h"
#include "mainwindow.h"

int q_a[40];
int th;
int t_T;
int uid;


MainWindow_stud::MainWindow_stud(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_stud)
{
    ui->setupUi(this);
    on_pushButton_4_clicked();
}

MainWindow_stud::~MainWindow_stud()
{
    delete ui;
}

void MainWindow_stud::set_uid(int id) {

    /* Initializing variables */
    extern int uid;
    uid = id;
}

void MainWindow_stud::on_pushButton_clicked()
{

    /* Initializing variables */
    dialog3 = new Dialog3(this);

    /* Main part */
    dialog3->setModal(true);
    dialog3->show();
    dialog3->select_test_type(0);
}

void MainWindow_stud::on_pushButton_2_clicked()
{

    /* Initializing variables */
    dialog3 = new Dialog3(this);

    /* Main part */
    dialog3->setModal(true);
    dialog3->show();
    dialog3->select_test_type(1);
}

void MainWindow_stud::on_pushButton_3_clicked()
{

    /* Main part */
    final_test();
}

void MainWindow_stud::practice(int theme) {

    /* Initializing variables */
    static int i = 0;
    int choice;
    static struct Question *quest = nullptr;
    extern int q_a[40];
    extern int t_T;
    t_T = 1;
    extern int th;
    th = theme;
    QString Qth = (!theme) ? "Loops. " : (theme == 1) ? "Arrays. " : (theme == 2)  ? "Strings. " :
                    (theme == 3) ? "Recursion. " : (theme == 4) ? "Structures. " : (theme == 5) ?
                    "Files. " : (theme == 6) ? "Pointers. " : "Dynamic memory. ";
    QString num;

    /* Main part */
    if (!i) {
        if ((quest = db_get_test(theme))) {
            ui->stackedWidget->setCurrentIndex(1);
            new_test_visible(false);
            ui->actionLog_out->setVisible(false);
        } else {
            QMessageBox::critical(this, "Error!", "Couldn't get test!");
            return;
        }
    }

    for ( ; i <= 10;) {
        if (i == 10) {
            break;
        } else if (i) {
            choice = (ui->radioButton->isChecked()) ? 0 : (ui->radioButton_2->isChecked()) ? 1 :
                                    (ui->radioButton_3->isChecked()) ? 2 : 3;
            *(q_a + (i - 1)) = choice;
        }

        ui->textEdit->setPlainText((quest + i)->value);
        ui->radioButton->setText((quest + i)->ans[0]);
        ui->radioButton_2->setText((quest + i)->ans[1]);
        ui->radioButton_3->setText((quest + i)->ans[2]);
        ui->radioButton_4->setText((quest + i)->ans[3]);

        ui->radioButton->setCheckable(false);
        ui->radioButton->setCheckable(true);
        ui->radioButton->setChecked(false);

        ui->radioButton_2->setCheckable(false);
        ui->radioButton_2->setCheckable(true);
        ui->radioButton_2->setChecked(false);

        ui->radioButton_3->setCheckable(false);
        ui->radioButton_3->setCheckable(true);
        ui->radioButton_3->setChecked(false);

        ui->radioButton_4->setCheckable(false);
        ui->radioButton_4->setCheckable(true);
        ui->radioButton_4->setChecked(false);

        MainWindow_stud::update();

        ui->pushButton_apply->setEnabled(false);
        num = (!i) ? "1" : (i == 1) ? "2" : (i == 2) ? "3" : (i == 3) ? "4" : (i == 4) ? "5" :
                        (i == 5) ? "6" : (i == 6) ? "7" : (i == 7) ? "8" : (i == 8) ? "9" : "10";
        ui->statusbar->showMessage(Qth + "Question " + num + "/10");

        ++i;
        return;
    }
    if (i == 10) {
        i = 0;
        show_results(theme, quest, q_a);
        delete quest;
    }
}

void MainWindow_stud::training(int theme) {

    /* Initializing variables */
    static int i = 0;
    int choice, wrong = 0;
    static struct Question *quest = nullptr;
    extern int t_T;
    t_T = 0;
    extern int th;
    th = theme;
    QString Qth = (!theme) ? "Loops. " : (theme == 1) ? "Arrays. " : (theme == 2)  ? "Strings. " :
                  (theme == 3) ? "Recursion. " : (theme == 4) ? "Structures. " : (theme == 5) ?
                   "Files. " : (theme == 6) ? "Pointers. " : "Dynamic memory. ";
    QString num;

    /* Main part */
    if (!i) {
        if ((quest = db_get_test(theme))) {
            ui->stackedWidget->setCurrentIndex(1);
            new_test_visible(false);
            ui->actionLog_out->setVisible(false);
        } else {
            QMessageBox::critical(this, "Error!", "Couldn't get test!");
            return;
        }
    }

    for ( ; i <= 10;) {
        if (i == 10) {
            break;
        } else if (i) {
            choice = (ui->radioButton->isChecked()) ? 0 : (ui->radioButton_2->isChecked()) ? 1 :
                                    (ui->radioButton_3->isChecked()) ? 2 : 3;
            if (choice != (quest + (i - 1))->correct) {
                --i;
                wrong = 1;
            }
        }

        ui->textEdit->setPlainText((quest + i)->value);
        ui->radioButton->setText((quest + i)->ans[0]);
        ui->radioButton_2->setText((quest + i)->ans[1]);
        ui->radioButton_3->setText((quest + i)->ans[2]);
        ui->radioButton_4->setText((quest + i)->ans[3]);

        ui->radioButton->setCheckable(false);
        ui->radioButton->setCheckable(true);
        ui->radioButton->setChecked(false);

        ui->radioButton_2->setCheckable(false);
        ui->radioButton_2->setCheckable(true);
        ui->radioButton_2->setChecked(false);

        ui->radioButton_3->setCheckable(false);
        ui->radioButton_3->setCheckable(true);
        ui->radioButton_3->setChecked(false);

        ui->radioButton_4->setCheckable(false);
        ui->radioButton_4->setCheckable(true);
        ui->radioButton_4->setChecked(false);

        MainWindow_stud::update();

        ui->pushButton_apply->setEnabled(false);
        num = (!i) ? "1" : (i == 1) ? "2" : (i == 2) ? "3" : (i == 3) ? "4" : (i == 4) ? "5" :
                        (i == 5) ? "6" : (i == 6) ? "7" : (i == 7) ? "8" : (i == 8) ? "9" : "10";
        ui->statusbar->showMessage(Qth + "Question " + num + "/10");
        if (wrong) {
            wrong = 0;
            ui->statusbar->showMessage("Error! Wrong answer!", 4000);
        }

        ++i;
        return;
    }
    if (i == 10) {
        i = 0;
        QMessageBox::information(this, "Student's mode", "You've passed the training!");
        ui->statusbar->showMessage("");
        on_pushButton_4_clicked();
        delete quest;
    }
}

void MainWindow_stud::on_pushButton_apply_clicked()
{

    /* Initializing variables */
    extern int th;
    extern int t_T;

    /* Main part */
    if (!t_T) {
        training(th);
    } else if (t_T == 1) {
        practice(th);
    } else {
        final_test();
    }
}

void MainWindow_stud::show_results(int theme, struct Question *q, int *q_a) {

    /* Initializing variables */
    extern int uid;
    int i, correct = 0, mark, max;
    char a[30];
    QTableWidgetItem *itm = nullptr;

    /* Main part */
    ui->stackedWidget->setCurrentIndex(2);
    ui->statusbar->showMessage("");
    ui->tableWidget->setRowCount(0);
    if (theme != 9) {
        ui->tableWidget->setRowCount(10);
    } else {
        ui->tableWidget->setRowCount(40);
    }
    max = (theme == 9) ? 40 : 10;
    for (i = 0; i < max; ++i) {
        ui->tableWidget->setItem(i, 0, (itm = new QTableWidgetItem((q + i)->value))); // Question
        itm->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 1, (itm = new QTableWidgetItem((q + i)->ans[*(q_a + i)]))); // User's answer
        itm->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 2, (itm = new QTableWidgetItem((q + i)->ans[(q + i)->correct]))); // Correct
        itm->setTextAlignment(Qt::AlignCenter);
        if ((q + i)->correct == *(q_a + i)) {
            color_row(i, 1);
            ++correct;
        } else {
            color_row(i, 0);
        }
    }

    if (theme != 9) {
        mark = correct / 2;
        mark = (mark < 2) ? 2 : mark;
        sprintf(a, "Your mark is %d [%d/10]", mark, correct);
    } else {
        mark = correct / 8;
        mark = (mark < 2) ? 2 : mark;
        sprintf(a, "Your mark is %d [%d/40]", mark, correct);
    }
    ui->label_Mark->setText(a);
    db_set_mark(uid, theme, mark);
}

void MainWindow_stud::on_radioButton_clicked()
{

    /* Main part */
    ui->pushButton_apply->setEnabled(true);
}

void MainWindow_stud::on_radioButton_2_clicked()
{

    /* Main part */
    ui->pushButton_apply->setEnabled(true);
}

void MainWindow_stud::on_radioButton_3_clicked()
{

    /* Main part */
    ui->pushButton_apply->setEnabled(true);
}

void MainWindow_stud::on_radioButton_4_clicked()
{

    /* Main part */
    ui->pushButton_apply->setEnabled(true);
}

void MainWindow_stud::color_row(int row, int correct) {

    /* Initializing variables */
    int i;

    /* Main part */
    for (i = 0; i < ui->tableWidget->columnCount(); ++i) {
        ui->tableWidget->item(row, i)->setBackgroundColor((correct) ? QColor(150, 255, 0) : QColor(255, 142, 142));
    }
}

void MainWindow_stud::on_pushButton_4_clicked()
{

    /* Main part */
    ui->stackedWidget->setCurrentIndex(0);
    new_test_visible(true);
    ui->actionLog_out->setVisible(true);
}

void MainWindow_stud::final_test() {

    /* Initializing variables */
    static int i = 0;
    int choice;
    static struct Question *quest = nullptr;
    extern int q_a[40];
    extern int t_T;
    t_T = 2;
    char num[3];
    QString Qnum;

    /* Main part */
    if (!i) {
        if ((quest = db_get_final_test())) {
            ui->stackedWidget->setCurrentIndex(1);
            new_test_visible(false);
            ui->actionLog_out->setVisible(false);
        } else {
            QMessageBox::critical(this, "Error!", "Couldn't get test!");
            return;
        }
    }

    for ( ; i <= 40;) {
        if (i == 40) {
            break;
        } else if (i) {
            choice = (ui->radioButton->isChecked()) ? 0 : (ui->radioButton_2->isChecked()) ? 1 :
                                    (ui->radioButton_3->isChecked()) ? 2 : 3;
            *(q_a + (i - 1)) = choice;
        }

        ui->textEdit->setPlainText((quest + i)->value);
        ui->radioButton->setText((quest + i)->ans[0]);
        ui->radioButton_2->setText((quest + i)->ans[1]);
        ui->radioButton_3->setText((quest + i)->ans[2]);
        ui->radioButton_4->setText((quest + i)->ans[3]);

        ui->radioButton->setCheckable(false);
        ui->radioButton->setCheckable(true);
        ui->radioButton->setChecked(false);

        ui->radioButton_2->setCheckable(false);
        ui->radioButton_2->setCheckable(true);
        ui->radioButton_2->setChecked(false);

        ui->radioButton_3->setCheckable(false);
        ui->radioButton_3->setCheckable(true);
        ui->radioButton_3->setChecked(false);

        ui->radioButton_4->setCheckable(false);
        ui->radioButton_4->setCheckable(true);
        ui->radioButton_4->setChecked(false);

        MainWindow_stud::update();

        ui->pushButton_apply->setEnabled(false);
        sprintf(num, "%d", i + 1);
        Qnum = num;
        ui->statusbar->showMessage("Final test. Question " + Qnum + "/40");

        ++i;
        return;
    }
    if (i == 40) {
        i = 0;
        show_results(9, quest, q_a);
        delete quest;
    }
}

void MainWindow_stud::on_actionLog_out_triggered()
{
    /* Initializing variables */
    QMessageBox::StandardButton reply;

    /* Main part */
    reply = QMessageBox::question(this, "Teacher's mode", "Are you sure you want to log out?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {

        /* Forum's code */
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
            mw->show();
            hide();

            this->hide();
        }
    }
}

void MainWindow_stud::on_actionExit_triggered()
{

    /* Initializing variables */
    QMessageBox::StandardButton reply;

    /* Main part */
    reply = QMessageBox::question(this, "Teacher's mode", "Are you sure you want to exit?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        db_close();
        this->close();
    }
}

void MainWindow_stud::on_actionGet_help_online_triggered()
{
    /* Main part */
    bool open = QDesktopServices::openUrl(QUrl("https://github.com/tushino-llc/ProTest/blob/master/README.md", QUrl::TolerantMode));
    if (open) {

    } else {
        QMessageBox::critical(this, "Error!", "Couldn't open help webpage!");
    }
}

void MainWindow_stud::on_actionAbout_triggered()
{
    QMessageBox::about(this, "Student's mode", "ProTest — A free powerful program for educational tests."
                                               "\n\nLicenced only under GNU GPL v2 copyleft."
                                               "\n\nBugreport email: anton2920@gmail.com");
}

void MainWindow_stud::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this, "Student's mode");
}

void MainWindow_stud::new_test_visible(bool is) {

    /* Main part */
    if (!is) {
        ui->menuNew->setEnabled(false);
    } else {
        ui->menuNew->setEnabled(true);
    }
}

void MainWindow_stud::on_actionLoops_triggered()
{

    /* Main part */
    training(0);
}

void MainWindow_stud::on_actionArrays_triggered()
{

    /* Main part */
    training(1);
}

void MainWindow_stud::on_actionStrings_triggered()
{

    /* Main part */
    training(2);
}

void MainWindow_stud::on_actionRecursion_triggered()
{

    /* Main part */
    training(3);
}

void MainWindow_stud::on_actionStructs_triggered()
{

    /* Main part */
    training(4);
}

void MainWindow_stud::on_actionFiles_triggered()
{

    /* Main part */
    training(5);
}

void MainWindow_stud::on_actionPointers_triggered()
{

    /* Main part */
    training(6);
}

void MainWindow_stud::on_actionDynamic_memory_triggered()
{

    /* Main part */
    training(7);
}

void MainWindow_stud::on_actionLoops_2_triggered()
{

    /* Main part */
    practice(0);
}

void MainWindow_stud::on_actionArrays_2_triggered()
{

    /* Main part */
    practice(1);
}

void MainWindow_stud::on_actionStrings_2_triggered()
{

    /* Main part */
    practice(2);
}

void MainWindow_stud::on_actionRecursion_2_triggered()
{

    /* Main part */
    practice(3);
}

void MainWindow_stud::on_actionStructs_2_triggered()
{

    /* Main part */
    practice(4);
}

void MainWindow_stud::on_actionFiles_2_triggered()
{

    /* Main part */
    practice(5);
}

void MainWindow_stud::on_actionPointers_2_triggered()
{

    /* Main part */
    practice(6);
}

void MainWindow_stud::on_actionDynamic_memory_2_triggered()
{

    /* Main part */
    practice(7);
}

void MainWindow_stud::on_MainWindow_stud_destroyed()
{

    /* Main part */
    db_close();
}

void MainWindow_stud::on_actionFinal_test_triggered()
{

    /* Main part */
    final_test();
}
