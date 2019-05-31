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

#include "mainwindow_teach.h"
#include "../build-qt-Desktop-Debug/ui_mainwindow_teach.h"
#include "mainwindow.h"
#include "../headers/database.h"

extern sqlite3 *db;

MainWindow_teach::MainWindow_teach(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_teach)
{
    ui->setupUi(this);
}

MainWindow_teach::~MainWindow_teach()
{
    delete ui;
}

void MainWindow_teach::Set_init_mode(int mode) {

    /* Main part */
    if (!mode) {
        ui->actionStudents_2->setChecked(true);
        ui->actionQuestions->setChecked(false);
        ui->actionAllow->setVisible(true);
        // ui->actionNew_Database->setVisible(false);
        ui->actionOpen_Database->setVisible(false);
        ui->actionClose_Database->setVisible(false);
        ui->actionAllow->setVisible(true);
        ui->actionRefresh->setText("Refresh students");
    } else {
        ui->actionStudents_2->setChecked(false);
        ui->actionQuestions->setChecked(true);
        ui->actionAllow->setVisible(false);
        // ui->actionNew_Database->setVisible(true);
        ui->actionOpen_Database->setVisible(false);
        ui->actionClose_Database->setVisible(false);
        ui->actionAllow->setVisible(false);
        ui->actionRefresh->setText("Refresh questions");
    }


    ui->stackedWidget->setCurrentIndex(mode);
    refresh_users();
}

void MainWindow_teach::on_actionStudents_2_triggered()
{

    /* Main part */
    Set_init_mode(0);
}

void MainWindow_teach::on_actionQuestions_triggered()
{

    /* Main part */
    Set_init_mode(1);
}

void MainWindow_teach::on_actionExit_triggered()
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

void MainWindow_teach::on_comboBox_currentIndexChanged(int index)
{
    /* Initializing variables */
    char a[10];
    sprintf(a, "%d", index);
    int id = 0;
    double mean = 0.0;
    struct Marks mks;
    struct User usr;

    /* Main part */
    if (index) {
        id = get_student_id(ui->comboBox->currentIndex());
        if (!id) {
            return;
        }
        mks = db_get_user_marks(id);
        usr = db_get_user(id);
        ui->lineFN->setText(usr.first_name);
        ui->lineLN->setText(usr.last_name);
        ui->lineLogin->setText(usr.login);
        sprintf(a, "%d", usr.id);
        ui->lineID->setText(a);

        sprintf(a, "%d", mks.values[0]);
        ui->lineLoops->setText(a);
        sprintf(a, "%d", mks.values[1]);
        ui->lineArrays->setText(a);
        sprintf(a, "%d", mks.values[2]);
        ui->lineStrings->setText(a);
        sprintf(a, "%d", mks.values[3]);
        ui->lineRecursion->setText(a);
        sprintf(a, "%d", mks.values[4]);
        ui->lineStructures->setText(a);
        sprintf(a, "%d", mks.values[5]);
        ui->lineFiles->setText(a);
        sprintf(a, "%d", mks.values[6]);
        ui->linePointers->setText(a);
        sprintf(a, "%d", mks.values[7]);
        ui->lineDyn_Mem->setText(a);
        sprintf(a, "%d", mks.values[9]);
        ui->lineFinal->setText(a);

        mean = get_mean(id);
        sprintf(a, "%6.3lf", mean);
        ui->lineMean->setText(a);
    } else {
        ui->actionAllow->setChecked(false);
        ui->lineLoops->setReadOnly(true);
        ui->lineArrays->setReadOnly(true);
        ui->lineStrings->setReadOnly(true);
        ui->lineRecursion->setReadOnly(true);
        ui->lineStructures->setReadOnly(true);
        ui->lineFiles->setReadOnly(true);
        ui->linePointers->setReadOnly(true);
        ui->lineDyn_Mem->setReadOnly(true);
        ui->lineFinal->setReadOnly(true);
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);

        ui->lineFN->setText("");
        ui->lineLN->setText("");
        ui->lineLogin->setText("");
        ui->lineID->setText("");
        ui->lineLoops->setText("");
        ui->lineArrays->setText("");
        ui->lineStrings->setText("");
        ui->lineRecursion->setText("");
        ui->lineStructures->setText("");
        ui->lineFiles->setText("");
        ui->linePointers->setText("");
        ui->lineDyn_Mem->setText("");
        ui->lineFinal->setText("");
        ui->lineMean->setText("");
    }

    ui->pushButton_rm->setEnabled((index) ? true : false);
}

void MainWindow_teach::on_actionAllow_triggered()
{

    /* Main part */
    if (ui->comboBox->currentIndex()) {
        if ((ui->actionAllow->isChecked())) {
            ui->actionAllow->setChecked(true);
            ui->lineLoops->setReadOnly(false);
            ui->lineArrays->setReadOnly(false);
            ui->lineStrings->setReadOnly(false);
            ui->lineRecursion->setReadOnly(false);
            ui->lineStructures->setReadOnly(false);
            ui->lineFiles->setReadOnly(false);
            ui->linePointers->setReadOnly(false);
            ui->lineDyn_Mem->setReadOnly(false);
            ui->lineFinal->setReadOnly(false);
            ui->pushButton->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
        } else {
            ui->actionAllow->setChecked(false);
            ui->lineLoops->setReadOnly(true);
            ui->lineArrays->setReadOnly(true);
            ui->lineStrings->setReadOnly(true);
            ui->lineRecursion->setReadOnly(true);
            ui->lineStructures->setReadOnly(true);
            ui->lineFiles->setReadOnly(true);
            ui->linePointers->setReadOnly(true);
            ui->lineDyn_Mem->setReadOnly(true);
            ui->lineFinal->setReadOnly(true);
            ui->pushButton->setEnabled(false);
            ui->pushButton_2->setEnabled(false);
        }
    } else {
        ui->actionAllow->setChecked(false);
    }
}

void MainWindow_teach::on_actionLog_out_triggered()
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

void MainWindow_teach::on_actionOpen_Database_triggered()
{
    /* Initializing variables */
    QString file_name = QFileDialog::getOpenFileName(this, "Open database", PATH_TO_DB);
    QByteArray arr = file_name.toLocal8Bit();


    /* Main part */
    if (db_open(PATH_TO_DB) != -1) {
        init_users();
    } else {
        QMessageBox::critical(this, "Error!", "Couldn't open database!");
    }
}

void MainWindow_teach::on_actionClose_Database_triggered()
{

    /* Main part */
    db_close();
    remove_users();
}

void MainWindow_teach::on_pushButton_add_clicked()
{

    /* Initializing variables */
    dialog1 = new Dialog1(this);

    /* Main part */
    dialog1->setModal(true);
    dialog1->AddStudent();
    dialog1->show();

    refresh_users();
}

void MainWindow_teach::init_users() {

    /* Initializing variables */
    int size;
    struct User *usr;
    char fnln[515], id[10];

    /* Main part */
    usr = db_get_users(&size);
    for (int i = 0; i < size; ++i) {
        strcpy(fnln, "");
        sprintf(id, "%d", (usr + i)->id);
        strcat(fnln, id);
        strcat(fnln, ") ");
        strcat(fnln, (usr + i)->first_name);
        strcat(fnln, " ");
        strcat(fnln, (usr + i)->last_name);
        ui->comboBox->addItem(fnln);
    }

    init_table();

    delete usr;
    ui->pushButton_add->setEnabled(true);
}

void MainWindow_teach::remove_users() {

    /* Main part */
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox->clear();
    ui->comboBox->addItem("Choose a student...");
    ui->pushButton_add->setEnabled(false);

    remove_table();
}

void MainWindow_teach::refresh_users() {

    /* Main part */
    remove_users();
    init_users();
}

void MainWindow_teach::on_pushButton_rm_clicked()
{

    /* Initializing variables */
    int id;
    QMessageBox::StandardButton reply;

    /* Main part */
    id = get_student_id(ui->comboBox->currentIndex());
    reply = QMessageBox::question(this, "Teacher's mode", "Are you sure you want to delete this student?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        if (db_delete_user(id) != -1) {
            refresh_users();
        } else {
            QMessageBox::critical(this, "Error!", "Couldn't delete this student!");
        }
    }
}

int MainWindow_teach::get_student_id(int index) {

    /* Initializing variables */
    int id;
    QString Qstr;
    QByteArray arr;
    char id_s[530] = {};

    /* Main part */
    Qstr = ui->comboBox->itemText(index);
    arr = Qstr.toLocal8Bit();
    sprintf(id_s, "%s", arr.data());
    id = atoi(id_s);

    /* Returning value */
    return id;
}

void MainWindow_teach::on_pushButton_2_clicked()
{

    /* Initializing variables */
    int id = -1, score;
    QByteArray arr;
    double mean = 0.0;
    char a[10];

    /* Main part */
    id = get_student_id(ui->comboBox->currentIndex());

    if (!check_marks_fields()) {
        QMessageBox::critical(this, "Error!", "Wrong characters in mark fields!");
        return;
    }
    arr = ui->lineLoops->text().toLocal8Bit();
    score = atoi(arr.data());
    if ((score < 2 || score > 5) && score) {
        QMessageBox::critical(this, "Error!", "Wrong mark!");
        return;
    }
    if (db_set_mark(id, 0, score) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    }

    arr = ui->lineArrays->text().toLocal8Bit();
    score = atoi(arr.data());
    if (db_set_mark(id, 1, score) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    }

    arr = ui->lineStrings->text().toLocal8Bit();
    score = atoi(arr.data());
    if (db_set_mark(id, 2, score) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    }

    arr = ui->lineRecursion->text().toLocal8Bit();
    score = atoi(arr.data());
    if (db_set_mark(id, 3, score) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    }

    arr = ui->lineStructures->text().toLocal8Bit();
    score = atoi(arr.data());
    if (db_set_mark(id, 4, score) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    }

    arr = ui->lineFiles->text().toLocal8Bit();
    score = atoi(arr.data());
    if (db_set_mark(id, 5, score) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    }

    arr = ui->linePointers->text().toLocal8Bit();
    score = atoi(arr.data());
    if (db_set_mark(id, 6, score) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    }

    arr = ui->lineDyn_Mem->text().toLocal8Bit();
    score = atoi(arr.data());
    if (db_set_mark(id, 7, score) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    }

    arr = ui->lineFinal->text().toLocal8Bit();
    score = atoi(arr.data());
    if (db_set_mark(id, 9, score) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    }

    mean = get_mean(id);
    strcpy(a, "");
    sprintf(a, "%.3lf", mean);
    ui->lineMean->setText("");
    ui->lineMean->setText(a);

    remove_table();
    init_table();
}

void MainWindow_teach::on_pushButton_clicked()
{

    /* Initializing variables */
    int id = -1;
    double mean = 0.0;
    char a[10];

    /* Main part */
    id = get_student_id(ui->comboBox->currentIndex());

    if (db_set_mark(id, 0, 0) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    } else {
        ui->lineLoops->setText("0");
    }

    if (db_set_mark(id, 1, 0) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    } else {
        ui->lineArrays->setText("0");
    }

    if (db_set_mark(id, 2, 0) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    } else {
        ui->lineStrings->setText("0");
    }

    if (db_set_mark(id, 3, 0) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    } else {
        ui->lineRecursion->setText("0");
    }

    if (db_set_mark(id, 4, 0) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    } else {
        ui->lineStructures->setText("0");
    }

    if (db_set_mark(id, 5, 0) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    } else {
        ui->lineFiles->setText("0");
    }

    if (db_set_mark(id, 6, 0) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    } else {
        ui->linePointers->setText("0");
    }

    if (db_set_mark(id, 7, 0) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    } else {
        ui->lineDyn_Mem->setText("0");
    }

    if (db_set_mark(id, 9, 0) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update student's mark!");
        return;
    } else {
        ui->lineFinal->setText("0");
    }

    strcpy(a, "");
    sprintf(a, "%6.3lf", mean);
    ui->lineMean->setText("");
    ui->lineMean->setText(a);

    remove_table();
    init_table();
}

double MainWindow_teach::get_mean(int id) {

    /* Initializing variables */
    int counter = 0;
    struct Marks mks;
    double mean = 0.0;

    /* Main part */
    mks = db_get_user_marks(id);
    for (int i = 0; i < 10; ++i) {
        if (i == 8) {
            continue;
        }
        if (mks.values[i] >= 2 && mks.values[i] <= 5) {
            mean += mks.values[i];
            ++counter;
        }
    }
    if (counter == 0) {
        mean = 0.0;
    } else {
        mean /= counter;
    }

    /* Returning value */
    return mean;
}

void MainWindow_teach::on_actionRefresh_triggered()
{

    /* Main part */
    if (ui->actionRefresh->text() == "Refresh students") {
        refresh_users();
    } else {
        refresh_q();
    }
}

void MainWindow_teach::init_table() {

    /* Initializing variables */
    int size;
    struct User *usr;
    struct Marks mks;
    double mean = 0.0;
    char a[10];
    QTableWidgetItem *itm = nullptr;

    /* Main part */
    usr = db_get_users(&size);

    ui->tableWidget->setRowCount(size);
    for (int i = 0; i < size; ++i) {
        mks = db_get_user_marks((usr + i)->id);
        ui->tableWidget->setItem(i, 0, (itm = new QTableWidgetItem((usr + i)->first_name)));
        itm->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 1, (itm = new QTableWidgetItem((usr + i)->last_name)));
        itm->setTextAlignment(Qt::AlignCenter);

        sprintf(a, "%d", mks.values[0]);
        ui->tableWidget->setItem(i, 2, (itm = new QTableWidgetItem(a)));
        itm->setTextAlignment(Qt::AlignCenter);

        sprintf(a, "%d", mks.values[1]);
        ui->tableWidget->setItem(i, 3, (itm = new QTableWidgetItem(a)));
        itm->setTextAlignment(Qt::AlignCenter);

        sprintf(a, "%d", mks.values[2]);
        ui->tableWidget->setItem(i, 4, (itm = new QTableWidgetItem(a)));
        itm->setTextAlignment(Qt::AlignCenter);

        sprintf(a, "%d", mks.values[3]);
        ui->tableWidget->setItem(i, 5, (itm = new QTableWidgetItem(a)));
        itm->setTextAlignment(Qt::AlignCenter);

        sprintf(a, "%d", mks.values[4]);
        ui->tableWidget->setItem(i, 6, (itm = new QTableWidgetItem(a)));
        itm->setTextAlignment(Qt::AlignCenter);

        sprintf(a, "%d", mks.values[5]);
        ui->tableWidget->setItem(i, 7, (itm = new QTableWidgetItem(a)));
        itm->setTextAlignment(Qt::AlignCenter);

        sprintf(a, "%d", mks.values[6]);
        ui->tableWidget->setItem(i, 8, (itm = new QTableWidgetItem(a)));
        itm->setTextAlignment(Qt::AlignCenter);

        sprintf(a, "%d", mks.values[7]);
        ui->tableWidget->setItem(i, 9, (itm = new QTableWidgetItem(a)));
        itm->setTextAlignment(Qt::AlignCenter);

        sprintf(a, "%d", mks.values[9]);
        ui->tableWidget->setItem(i, 10, (itm = new QTableWidgetItem(a)));
        itm->setTextAlignment(Qt::AlignCenter);

        mean = get_mean((usr + i)->id);
        strcpy(a, "");
        sprintf(a, "%.3lf", mean);
        ui->tableWidget->setItem(i, 11, (itm = new QTableWidgetItem(a)));
        itm->setTextAlignment(Qt::AlignCenter);
    }

    delete usr;
}

void MainWindow_teach::remove_table() {

    /* Main part */
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setRowCount(1);
}

void MainWindow_teach::on_actionGet_Help_triggered()
{
    /* Main part */
    bool open = QDesktopServices::openUrl(QUrl("https://github.com/tushino-llc/ProTest/blob/master/README.md", QUrl::TolerantMode));
    if (open) {

    } else {
        QMessageBox::critical(this, "Error!", "Couldn't open help webpage!");
    }
}

void MainWindow_teach::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this, "Teacher's mode");
}

void MainWindow_teach::on_actionAbout_triggered()
{
    QMessageBox::about(this, "Teacher's mode", "ProTest — A free powerful program for educational tests."
                                               "\n\nLicenced only under GNU GPL v2 copyleft."
                                               "\n\nBugreport email: anton2920@gmail.com");
}

void MainWindow_teach::init_q() {

    /* Initializing variables */
    int theme, i, size, q_id;
    struct Question *quest = nullptr;
    char a[MAX_LEN + 10];

    /* Main part */
    theme = ui->comboBox_2->currentIndex() - 1;

    if ((quest = db_get_questions(&size, theme)) != nullptr) {
        for (i = 0; i < size; ++i) {
            q_id = (quest + i)->id;
            sprintf(a, "%d) %s", q_id, (quest + i)->value);
            ui->comboBox_3->addItem(a);
        }
    } else {
        QMessageBox::critical(this, "Error!", "Couldn't retrieve questions!");
        ui->comboBox_3->setCurrentIndex(0);
        return;
    }

    delete quest;
}

void MainWindow_teach::remove_q() {

    /* Main part */
    ui->comboBox_3->clear();
    ui->comboBox_3->addItem("Question...");

    ui->radioButton_A1->setCheckable(false);
    ui->radioButton_A1->setChecked(false);

    ui->radioButton_A2->setCheckable(false);
    ui->radioButton_A2->setChecked(false);

    ui->radioButton_A3->setCheckable(false);
    ui->radioButton_A3->setChecked(false);

    ui->radioButton_A4->setCheckable(false);
    ui->radioButton_A4->setChecked(false);

    ui->radioButton_A1->setCheckable(true);
    ui->radioButton_A2->setCheckable(true);
    ui->radioButton_A3->setCheckable(true);
    ui->radioButton_A4->setCheckable(true);

    ui->lineA1->setText("");
    ui->lineA2->setText("");
    ui->lineA3->setText("");
    ui->lineA4->setText("");

    ui->textEdit->setPlainText("");

    ui->pushButton_apply->setEnabled(false);
}

void MainWindow_teach::refresh_q() {

    /* Main part */
    remove_q();
    init_q();
}

void MainWindow_teach::on_pushButton_Rem_Q_clicked()
{

    /* Initializing variables */
    QMessageBox::StandardButton reply;
    int id;

    /* Main part */
    reply = QMessageBox::question(this, "Teacher's mode", "Are you sure you want to delete this question?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        id = get_question_id(ui->comboBox_3->currentIndex());
        if (db_delete_question(id) == -1) {
            QMessageBox::critical(this, "Error!", "Couldn't delete question!");
        } else {
            refresh_q();
        }
    }

}

void MainWindow_teach::on_pushButton_Add_Q_clicked()
{

    /* Main part */
    dialog2 = new Dialog2(this);
    dialog2->setModal(true);
    dialog2->show();
}

void MainWindow_teach::on_comboBox_2_currentIndexChanged(int index)
{

    /* Main part */
    if (index) {
        refresh_q();
    } else {
        ui->comboBox_3->setCurrentIndex(0);
    }
}

void MainWindow_teach::on_comboBox_3_currentIndexChanged(int index)
{

    /* Initializing variables */
    int id;
    struct Question quest;

    /* Main part */
    if (index) {
        id = get_question_id(ui->comboBox_3->currentIndex());
        if (!id) {
            return;
        }

        quest = db_get_question_by_id(id);

        ui->textEdit->setPlainText(quest.value);

        ui->lineA1->setText(quest.ans[0]);
        ui->lineA2->setText(quest.ans[1]);
        ui->lineA3->setText(quest.ans[2]);
        ui->lineA4->setText(quest.ans[3]);

        switch (quest.correct) {
            case 0:
                ui->radioButton_A1->setChecked(true);
                break;
            case 1:
                ui->radioButton_A2->setChecked(true);
                break;
            case 2:
                ui->radioButton_A3->setChecked(true);
                break;
            case 3:
                ui->radioButton_A4->setChecked(true);
                break;
            default:
                break;
        }

        ui->pushButton_apply->setEnabled(false);
    } else {
        ui->pushButton_apply->setEnabled(false);
        ui->pushButton_rm->setEnabled(false);

        ui->radioButton_A1->setCheckable(false);
        ui->radioButton_A2->setCheckable(false);
        ui->radioButton_A3->setCheckable(false);
        ui->radioButton_A4->setCheckable(false);

        ui->radioButton_A1->setCheckable(true);
        ui->radioButton_A2->setCheckable(true);
        ui->radioButton_A3->setCheckable(true);
        ui->radioButton_A4->setCheckable(true);

        ui->lineA1->setText("");
        ui->lineA2->setText("");
        ui->lineA3->setText("");
        ui->lineA4->setText("");

        ui->textEdit->setPlainText("");

        MainWindow_teach::update();
    }
}

int MainWindow_teach::get_question_id(int index) {

    /* Initializing variables */
    int id;
    QString Qstr;
    QByteArray arr;
    char id_s[MAX_LEN + 10] = {};

    /* Main part */
    Qstr = ui->comboBox_3->itemText(index);
    arr = Qstr.toLocal8Bit();
    sprintf(id_s, "%s", arr.data());
    id = atoi(id_s);

    /* Returning value */
    return id;
}

void MainWindow_teach::on_pushButton_apply_clicked()
{

    /* Initializing variables */
    struct Question quest;
    QByteArray arr;

    /* Main part */
    quest.theme = ui->comboBox_2->currentIndex() - 1;

    arr = ui->textEdit->toPlainText().toLocal8Bit();
    strcpy(quest.value, arr.data());

    arr = ui->lineA1->text().toLocal8Bit();
    strcpy(quest.ans[0], arr.data());

    arr = ui->lineA2->text().toLocal8Bit();
    strcpy(quest.ans[1], arr.data());

    arr = ui->lineA3->text().toLocal8Bit();
    strcpy(quest.ans[2], arr.data());

    arr = ui->lineA4->text().toLocal8Bit();
    strcpy(quest.ans[3], arr.data());

    quest.correct = (ui->radioButton_A1->isChecked()) ? 0 : (ui->radioButton_A2->isChecked()) ?
                    1 : (ui->radioButton_A3->isChecked()) ? 2 : 3;

    quest.id = get_question_id(ui->comboBox_3->currentIndex());

    if (db_update_question(quest) == -1) {
        QMessageBox::critical(this, "Error!", "Couldn't update question!");
    } else {
        ui->pushButton_apply->setEnabled(false);
    }
}

void MainWindow_teach::on_lineA1_textChanged(const QString &arg1)
{
    /* VarCheck */
    if (check_all_fields()) {
        ui->pushButton_apply->setEnabled(true);
    }
}

void MainWindow_teach::on_lineA2_textChanged(const QString &arg1)
{
    /* VarCheck */
    if (check_all_fields()) {
        ui->pushButton_apply->setEnabled(true);
    }
}

void MainWindow_teach::on_lineA3_textChanged(const QString &arg1)
{
    /* VarCheck */
    if (check_all_fields()) {
        ui->pushButton_apply->setEnabled(true);
    }
}

void MainWindow_teach::on_lineA4_textChanged(const QString &arg1)
{
    /* VarCheck */
    if (check_all_fields()) {
        ui->pushButton_apply->setEnabled(true);
    }
}

void MainWindow_teach::on_textEdit_textChanged()
{
    /* VarCheck */
    if (check_all_fields()) {
        ui->pushButton_apply->setEnabled(true);
    }
}

void MainWindow_teach::on_radioButton_A1_clicked()
{
    /* VarCheck */
    if (check_all_fields()) {
        ui->pushButton_apply->setEnabled(true);
    }
}

void MainWindow_teach::on_radioButton_A2_clicked()
{
    /* VarCheck */
    if (check_all_fields()) {
        ui->pushButton_apply->setEnabled(true);
    }
}

void MainWindow_teach::on_radioButton_A3_clicked()
{
    /* VarCheck */
    if (check_all_fields()) {
        ui->pushButton_apply->setEnabled(true);
    }
}

void MainWindow_teach::on_radioButton_A4_clicked()
{
    /* VarCheck */
    if (check_all_fields()) {
        ui->pushButton_apply->setEnabled(true);
    }
}

int MainWindow_teach::check_all_fields() {

   /* VarCheck */
   if (ui->textEdit->toPlainText() != "" && ui->lineA1->text() != "" && ui->lineA2->text() != "" &&
           ui->lineA3->text() != "" && ui->lineA4->text() != "" && (ui->radioButton_A1->isChecked() ||
                                                                    ui->radioButton_A2->isChecked() ||
                                                                    ui->radioButton_A3->isChecked() ||
                                                                    ui->radioButton_A4->isChecked())) {
       return 1;
   } else {
       return 0;
   }
}

void MainWindow_teach::on_MainWindow_teach_destroyed()
{

    /* Main part */
    db_close();
}

int MainWindow_teach::check_marks_fields() {

    /* Initializing variables */
    int i;
    char *curr = nullptr;
    QString Qcurr;
    QByteArray arr;

    /* Main part */
    Qcurr = ui->lineLoops->text();
    arr = Qcurr.toLocal8Bit();
    curr = arr.data();
    for (i = 0; i < static_cast<int>(strlen(curr)); ++i) {
        if ((*(curr + i) < '2' || *(curr + i) > '5') && *(curr + i) != '0') {
            return 0;
        }
    }

    Qcurr = ui->lineArrays->text();
    arr = Qcurr.toLocal8Bit();
    curr = arr.data();
    for (i = 0; i < static_cast<int>(strlen(curr)); ++i) {
        if ((*(curr + i) < '2' || *(curr + i) > '5') && *(curr + i) != '0') {
            return 0;
        }
    }

    Qcurr = ui->lineStrings->text();
    arr = Qcurr.toLocal8Bit();
    curr = arr.data();
    for (i = 0; i < static_cast<int>(strlen(curr)); ++i) {
        if ((*(curr + i) < '2' || *(curr + i) > '5') && *(curr + i) != '0') {
            return 0;
        }
    }

    Qcurr = ui->lineRecursion->text();
    arr = Qcurr.toLocal8Bit();
    curr = arr.data();
    for (i = 0; i < static_cast<int>(strlen(curr)); ++i) {
        if ((*(curr + i) < '2' || *(curr + i) > '5') && *(curr + i) != '0') {
            return 0;
        }
    }

    Qcurr = ui->lineStructures->text();
    arr = Qcurr.toLocal8Bit();
    curr = arr.data();
    for (i = 0; i < static_cast<int>(strlen(curr)); ++i) {
        if ((*(curr + i) < '2' || *(curr + i) > '5') && *(curr + i) != '0') {
            return 0;
        }
    }

    Qcurr = ui->lineFiles->text();
    arr = Qcurr.toLocal8Bit();
    curr = arr.data();
    for (i = 0; i < static_cast<int>(strlen(curr)); ++i) {
        if ((*(curr + i) < '2' || *(curr + i) > '5') && *(curr + i) != '0') {
            return 0;
        }
    }

    Qcurr = ui->linePointers->text();
    arr = Qcurr.toLocal8Bit();
    curr = arr.data();
    for (i = 0; i < static_cast<int>(strlen(curr)); ++i) {
        if ((*(curr + i) < '2' || *(curr + i) > '5') && *(curr + i) != '0') {
            return 0;
        }
    }

    Qcurr = ui->lineDyn_Mem->text();
    arr = Qcurr.toLocal8Bit();
    curr = arr.data();
    for (i = 0; i < static_cast<int>(strlen(curr)); ++i) {
        if ((*(curr + i) < '2' || *(curr + i) > '5') && *(curr + i) != '0') {
            return 0;
        }
    }

    Qcurr = ui->lineFinal->text();
    arr = Qcurr.toLocal8Bit();
    curr = arr.data();
    for (i = 0; i < static_cast<int>(strlen(curr)); ++i) {
        if ((*(curr + i) < '2' || *(curr + i) > '5') && *(curr + i) != '0') {
            return 0;
        }
    }

    /* Returning value */
    return 1;
}

void MainWindow_teach::refresh_table() {

    /* Main part */
    remove_table();
    init_table();
}
