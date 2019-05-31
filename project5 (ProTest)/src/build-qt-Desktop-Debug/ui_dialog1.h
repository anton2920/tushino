/********************************************************************************
** Form generated from reading UI file 'dialog1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG1_H
#define UI_DIALOG1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog1
{
public:
    QLineEdit *lineEditLN;
    QRadioButton *radioTeacher;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *lineEditPass;
    QLineEdit *lineEditFN;
    QRadioButton *radioStudent;
    QLabel *label;
    QLineEdit *lineEditLogin;
    QLabel *label_5;
    QLabel *label_3;
    QPushButton *pushSignUp;
    QLabel *label_7;
    QLineEdit *lineEditPass_2;

    void setupUi(QDialog *Dialog1)
    {
        if (Dialog1->objectName().isEmpty())
            Dialog1->setObjectName(QString::fromUtf8("Dialog1"));
        Dialog1->resize(400, 540);
        Dialog1->setMinimumSize(QSize(400, 540));
        Dialog1->setMaximumSize(QSize(400, 540));
        Dialog1->setSizeGripEnabled(false);
        lineEditLN = new QLineEdit(Dialog1);
        lineEditLN->setObjectName(QString::fromUtf8("lineEditLN"));
        lineEditLN->setGeometry(QRect(30, 200, 331, 32));
        QFont font;
        font.setPointSize(11);
        lineEditLN->setFont(font);
        radioTeacher = new QRadioButton(Dialog1);
        radioTeacher->setObjectName(QString::fromUtf8("radioTeacher"));
        radioTeacher->setGeometry(QRect(210, 427, 101, 22));
        QFont font1;
        font1.setPointSize(14);
        radioTeacher->setFont(font1);
        label_2 = new QLabel(Dialog1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 240, 59, 18));
        QFont font2;
        font2.setPointSize(12);
        label_2->setFont(font2);
        label_4 = new QLabel(Dialog1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 10, 191, 61));
        QFont font3;
        font3.setPointSize(40);
        label_4->setFont(font3);
        label_6 = new QLabel(Dialog1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 120, 91, 18));
        label_6->setFont(font2);
        lineEditPass = new QLineEdit(Dialog1);
        lineEditPass->setObjectName(QString::fromUtf8("lineEditPass"));
        lineEditPass->setGeometry(QRect(30, 320, 331, 32));
        lineEditPass->setFont(font);
        lineEditPass->setEchoMode(QLineEdit::Password);
        lineEditFN = new QLineEdit(Dialog1);
        lineEditFN->setObjectName(QString::fromUtf8("lineEditFN"));
        lineEditFN->setGeometry(QRect(30, 140, 331, 32));
        lineEditFN->setFont(font);
        radioStudent = new QRadioButton(Dialog1);
        radioStudent->setObjectName(QString::fromUtf8("radioStudent"));
        radioStudent->setGeometry(QRect(90, 427, 101, 22));
        radioStudent->setFont(font1);
        label = new QLabel(Dialog1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 50, 271, 51));
        QFont font4;
        font4.setPointSize(17);
        label->setFont(font4);
        label->setAlignment(Qt::AlignCenter);
        lineEditLogin = new QLineEdit(Dialog1);
        lineEditLogin->setObjectName(QString::fromUtf8("lineEditLogin"));
        lineEditLogin->setGeometry(QRect(30, 260, 331, 32));
        lineEditLogin->setFont(font);
        label_5 = new QLabel(Dialog1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 180, 81, 20));
        label_5->setFont(font2);
        label_3 = new QLabel(Dialog1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 300, 81, 20));
        label_3->setFont(font2);
        pushSignUp = new QPushButton(Dialog1);
        pushSignUp->setObjectName(QString::fromUtf8("pushSignUp"));
        pushSignUp->setEnabled(false);
        pushSignUp->setGeometry(QRect(30, 470, 331, 51));
        pushSignUp->setFont(font4);
        label_7 = new QLabel(Dialog1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 360, 141, 20));
        label_7->setFont(font2);
        lineEditPass_2 = new QLineEdit(Dialog1);
        lineEditPass_2->setObjectName(QString::fromUtf8("lineEditPass_2"));
        lineEditPass_2->setGeometry(QRect(30, 380, 331, 32));
        lineEditPass_2->setFont(font);
        lineEditPass_2->setEchoMode(QLineEdit::Password);
        QWidget::setTabOrder(lineEditFN, lineEditLN);
        QWidget::setTabOrder(lineEditLN, lineEditLogin);
        QWidget::setTabOrder(lineEditLogin, lineEditPass);
        QWidget::setTabOrder(lineEditPass, lineEditPass_2);
        QWidget::setTabOrder(lineEditPass_2, radioStudent);
        QWidget::setTabOrder(radioStudent, radioTeacher);
        QWidget::setTabOrder(radioTeacher, pushSignUp);

        retranslateUi(Dialog1);

        QMetaObject::connectSlotsByName(Dialog1);
    } // setupUi

    void retranslateUi(QDialog *Dialog1)
    {
        Dialog1->setWindowTitle(QApplication::translate("Dialog1", "Sign Up", nullptr));
        radioTeacher->setText(QApplication::translate("Dialog1", "Teacher", nullptr));
        label_2->setText(QApplication::translate("Dialog1", "Login", nullptr));
        label_4->setText(QApplication::translate("Dialog1", "ProTest", nullptr));
        label_6->setText(QApplication::translate("Dialog1", "First name", nullptr));
        radioStudent->setText(QApplication::translate("Dialog1", "Student", nullptr));
        label->setText(QApplication::translate("Dialog1", "Sign up", nullptr));
        label_5->setText(QApplication::translate("Dialog1", "Last name", nullptr));
        label_3->setText(QApplication::translate("Dialog1", "Password", nullptr));
        pushSignUp->setText(QApplication::translate("Dialog1", "Sign Up", nullptr));
        label_7->setText(QApplication::translate("Dialog1", "Confirm Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog1: public Ui_Dialog1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG1_H
