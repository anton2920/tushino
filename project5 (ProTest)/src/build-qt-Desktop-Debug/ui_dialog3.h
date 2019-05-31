/********************************************************************************
** Form generated from reading UI file 'dialog3.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG3_H
#define UI_DIALOG3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog3
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton_Loops;
    QPushButton *pushButton_Arrays;
    QPushButton *pushButton_Strings;
    QPushButton *pushButton_Recursion;
    QPushButton *pushButton_Structures;
    QPushButton *pushButton_Files;
    QPushButton *pushButton_Pointers;
    QPushButton *pushButton_Dyn_Mem;

    void setupUi(QDialog *Dialog3)
    {
        if (Dialog3->objectName().isEmpty())
            Dialog3->setObjectName(QString::fromUtf8("Dialog3"));
        Dialog3->resize(400, 540);
        Dialog3->setMinimumSize(QSize(400, 540));
        Dialog3->setMaximumSize(QSize(400, 540));
        verticalLayout = new QVBoxLayout(Dialog3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Dialog3);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(25);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        pushButton_Loops = new QPushButton(Dialog3);
        pushButton_Loops->setObjectName(QString::fromUtf8("pushButton_Loops"));
        QFont font1;
        font1.setPointSize(14);
        pushButton_Loops->setFont(font1);

        verticalLayout->addWidget(pushButton_Loops);

        pushButton_Arrays = new QPushButton(Dialog3);
        pushButton_Arrays->setObjectName(QString::fromUtf8("pushButton_Arrays"));
        pushButton_Arrays->setFont(font1);

        verticalLayout->addWidget(pushButton_Arrays);

        pushButton_Strings = new QPushButton(Dialog3);
        pushButton_Strings->setObjectName(QString::fromUtf8("pushButton_Strings"));
        pushButton_Strings->setFont(font1);

        verticalLayout->addWidget(pushButton_Strings);

        pushButton_Recursion = new QPushButton(Dialog3);
        pushButton_Recursion->setObjectName(QString::fromUtf8("pushButton_Recursion"));
        pushButton_Recursion->setFont(font1);

        verticalLayout->addWidget(pushButton_Recursion);

        pushButton_Structures = new QPushButton(Dialog3);
        pushButton_Structures->setObjectName(QString::fromUtf8("pushButton_Structures"));
        pushButton_Structures->setFont(font1);

        verticalLayout->addWidget(pushButton_Structures);

        pushButton_Files = new QPushButton(Dialog3);
        pushButton_Files->setObjectName(QString::fromUtf8("pushButton_Files"));
        pushButton_Files->setFont(font1);

        verticalLayout->addWidget(pushButton_Files);

        pushButton_Pointers = new QPushButton(Dialog3);
        pushButton_Pointers->setObjectName(QString::fromUtf8("pushButton_Pointers"));
        pushButton_Pointers->setFont(font1);

        verticalLayout->addWidget(pushButton_Pointers);

        pushButton_Dyn_Mem = new QPushButton(Dialog3);
        pushButton_Dyn_Mem->setObjectName(QString::fromUtf8("pushButton_Dyn_Mem"));
        pushButton_Dyn_Mem->setFont(font1);

        verticalLayout->addWidget(pushButton_Dyn_Mem);


        retranslateUi(Dialog3);

        QMetaObject::connectSlotsByName(Dialog3);
    } // setupUi

    void retranslateUi(QDialog *Dialog3)
    {
        Dialog3->setWindowTitle(QApplication::translate("Dialog3", "Select topic", nullptr));
        label->setText(QApplication::translate("Dialog3", "Select topic", nullptr));
        pushButton_Loops->setText(QApplication::translate("Dialog3", "Loops", nullptr));
        pushButton_Arrays->setText(QApplication::translate("Dialog3", "Arrays", nullptr));
        pushButton_Strings->setText(QApplication::translate("Dialog3", "Strings", nullptr));
        pushButton_Recursion->setText(QApplication::translate("Dialog3", "Recursion", nullptr));
        pushButton_Structures->setText(QApplication::translate("Dialog3", "Structures", nullptr));
        pushButton_Files->setText(QApplication::translate("Dialog3", "Files", nullptr));
        pushButton_Pointers->setText(QApplication::translate("Dialog3", "Pointers", nullptr));
        pushButton_Dyn_Mem->setText(QApplication::translate("Dialog3", "Dynamic memory", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog3: public Ui_Dialog3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG3_H
