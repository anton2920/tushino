/********************************************************************************
** Form generated from reading UI file 'dialog2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG2_H
#define UI_DIALOG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog2
{
public:
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QLineEdit *lineEdit;
    QRadioButton *radioButton_2;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton_3;
    QLineEdit *lineEdit_3;
    QRadioButton *radioButton_4;
    QLineEdit *lineEdit_4;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QTextEdit *textEdit;

    void setupUi(QDialog *Dialog2)
    {
        if (Dialog2->objectName().isEmpty())
            Dialog2->setObjectName(QString::fromUtf8("Dialog2"));
        Dialog2->resize(400, 540);
        Dialog2->setMinimumSize(QSize(400, 540));
        Dialog2->setMaximumSize(QSize(400, 540));
        label = new QLabel(Dialog2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 0, 211, 71));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(Dialog2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(30, 80, 341, 41));
        QFont font1;
        font1.setPointSize(12);
        comboBox->setFont(font1);
        pushButton = new QPushButton(Dialog2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setGeometry(QRect(30, 450, 341, 61));
        QFont font2;
        font2.setPointSize(18);
        pushButton->setFont(font2);
        groupBox = new QGroupBox(Dialog2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 280, 341, 151));
        groupBox->setFont(font1);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QFont font3;
        font3.setPointSize(11);
        lineEdit->setFont(font3);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font3);

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout->addWidget(radioButton_3, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFont(font3);

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout->addWidget(radioButton_4, 3, 0, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFont(font3);

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 1);

        layoutWidget = new QWidget(Dialog2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 140, 341, 131));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setFont(font1);

        formLayout->setWidget(1, QFormLayout::SpanningRole, textEdit);

        QWidget::setTabOrder(comboBox, textEdit);
        QWidget::setTabOrder(textEdit, radioButton);
        QWidget::setTabOrder(radioButton, lineEdit);
        QWidget::setTabOrder(lineEdit, radioButton_2);
        QWidget::setTabOrder(radioButton_2, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, radioButton_3);
        QWidget::setTabOrder(radioButton_3, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, radioButton_4);
        QWidget::setTabOrder(radioButton_4, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, pushButton);

        retranslateUi(Dialog2);

        QMetaObject::connectSlotsByName(Dialog2);
    } // setupUi

    void retranslateUi(QDialog *Dialog2)
    {
        Dialog2->setWindowTitle(QApplication::translate("Dialog2", "Dialog", nullptr));
        label->setText(QApplication::translate("Dialog2", "Add question", nullptr));
        comboBox->setItemText(0, QApplication::translate("Dialog2", "Topic...", nullptr));
        comboBox->setItemText(1, QApplication::translate("Dialog2", "Loops", nullptr));
        comboBox->setItemText(2, QApplication::translate("Dialog2", "Arrays", nullptr));
        comboBox->setItemText(3, QApplication::translate("Dialog2", "Strings", nullptr));
        comboBox->setItemText(4, QApplication::translate("Dialog2", "Recursion", nullptr));
        comboBox->setItemText(5, QApplication::translate("Dialog2", "Structs", nullptr));
        comboBox->setItemText(6, QApplication::translate("Dialog2", "Files", nullptr));
        comboBox->setItemText(7, QApplication::translate("Dialog2", "Pointers", nullptr));
        comboBox->setItemText(8, QApplication::translate("Dialog2", "Dynamic memory", nullptr));

        pushButton->setText(QApplication::translate("Dialog2", "Add", nullptr));
        groupBox->setTitle(QApplication::translate("Dialog2", "Answers", nullptr));
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        radioButton_3->setText(QString());
        radioButton_4->setText(QString());
        label_2->setText(QApplication::translate("Dialog2", "Question", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog2: public Ui_Dialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG2_H
