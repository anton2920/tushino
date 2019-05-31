/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonSignIn;
    QPushButton *pushButtonSignUp;
    QCheckBox *checkBox;
    QLabel *label;
    QLabel *label_4;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineLogin;
    QWidget *layoutWidget1;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QLineEdit *linePass;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(474, 366);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(474, 366));
        MainWindow->setMaximumSize(QSize(474, 366));
        MainWindow->setInputMethodHints(Qt::ImhLatinOnly);
        MainWindow->setDocumentMode(false);
        MainWindow->setDockNestingEnabled(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButtonSignIn = new QPushButton(centralWidget);
        pushButtonSignIn->setObjectName(QString::fromUtf8("pushButtonSignIn"));
        pushButtonSignIn->setEnabled(false);
        pushButtonSignIn->setGeometry(QRect(70, 290, 161, 51));
        QFont font;
        font.setPointSize(15);
        pushButtonSignIn->setFont(font);
        pushButtonSignUp = new QPushButton(centralWidget);
        pushButtonSignUp->setObjectName(QString::fromUtf8("pushButtonSignUp"));
        pushButtonSignUp->setGeometry(QRect(240, 290, 161, 51));
        pushButtonSignUp->setFont(font);
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(70, 250, 151, 22));
        QFont font1;
        font1.setPointSize(12);
        checkBox->setFont(font1);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 50, 271, 51));
        QFont font2;
        font2.setPointSize(17);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 10, 191, 61));
        QFont font3;
        font3.setPointSize(40);
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 120, 331, 60));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineLogin = new QLineEdit(layoutWidget);
        lineLogin->setObjectName(QString::fromUtf8("lineLogin"));
        QFont font4;
        font4.setPointSize(11);
        lineLogin->setFont(font4);

        formLayout->setWidget(1, QFormLayout::SpanningRole, lineLogin);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(70, 180, 331, 61));
        formLayout_2 = new QFormLayout(layoutWidget1);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        linePass = new QLineEdit(layoutWidget1);
        linePass->setObjectName(QString::fromUtf8("linePass"));
        linePass->setFont(font4);
        linePass->setEchoMode(QLineEdit::Password);

        formLayout_2->setWidget(1, QFormLayout::SpanningRole, linePass);

        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(lineLogin, linePass);
        QWidget::setTabOrder(linePass, checkBox);
        QWidget::setTabOrder(checkBox, pushButtonSignIn);
        QWidget::setTabOrder(pushButtonSignIn, pushButtonSignUp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ProTest", nullptr));
        pushButtonSignIn->setText(QApplication::translate("MainWindow", "Sign In", nullptr));
        pushButtonSignUp->setText(QApplication::translate("MainWindow", "Sign Up", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "Remember me", nullptr));
        label->setText(QApplication::translate("MainWindow", "Authorize", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "ProTest", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Login", nullptr));
        lineLogin->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
