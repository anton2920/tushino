/********************************************************************************
** Form generated from reading UI file 'mainwindow_teach.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_TEACH_H
#define UI_MAINWINDOW_TEACH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_teach
{
public:
    QAction *actionOpen_Database;
    QAction *actionClose_Database;
    QAction *actionGet_Help;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *actionStudents;
    QAction *actionQuestions;
    QAction *actionStudents_2;
    QAction *actionExit;
    QAction *actionLog_out;
    QAction *actionAllow;
    QAction *actionRefresh;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QFormLayout *formLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox;
    QPushButton *pushButton_add;
    QPushButton *pushButton_rm;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineFN;
    QLabel *label_3;
    QLineEdit *lineLN;
    QLabel *label;
    QLineEdit *lineLogin;
    QLabel *label_14;
    QLineEdit *lineID;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QFormLayout *formLayout_3;
    QLabel *label_10;
    QLineEdit *lineRecursion;
    QLabel *label_9;
    QLabel *label_11;
    QLineEdit *lineStructures;
    QLineEdit *lineFiles;
    QFormLayout *formLayout_4;
    QLabel *label_4;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *linePointers;
    QLineEdit *lineDyn_Mem;
    QLineEdit *lineFinal;
    QLineEdit *lineMean;
    QLabel *label_5;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QLineEdit *lineLoops;
    QLineEdit *lineArrays;
    QLineEdit *lineStrings;
    QLabel *label_8;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QWidget *page_2;
    QGridLayout *gridLayout_5;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout_6;
    QRadioButton *radioButton_A1;
    QRadioButton *radioButton_A2;
    QLineEdit *lineA2;
    QRadioButton *radioButton_A3;
    QLineEdit *lineA3;
    QRadioButton *radioButton_A4;
    QLineEdit *lineA4;
    QLineEdit *lineA1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QPushButton *pushButton_Add_Q;
    QPushButton *pushButton_Rem_Q;
    QTextEdit *textEdit;
    QPushButton *pushButton_apply;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuWindow;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow_teach)
    {
        if (MainWindow_teach->objectName().isEmpty())
            MainWindow_teach->setObjectName(QString::fromUtf8("MainWindow_teach"));
        MainWindow_teach->resize(1133, 645);
        actionOpen_Database = new QAction(MainWindow_teach);
        actionOpen_Database->setObjectName(QString::fromUtf8("actionOpen_Database"));
        actionClose_Database = new QAction(MainWindow_teach);
        actionClose_Database->setObjectName(QString::fromUtf8("actionClose_Database"));
        actionGet_Help = new QAction(MainWindow_teach);
        actionGet_Help->setObjectName(QString::fromUtf8("actionGet_Help"));
        actionAbout = new QAction(MainWindow_teach);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindow_teach);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionStudents = new QAction(MainWindow_teach);
        actionStudents->setObjectName(QString::fromUtf8("actionStudents"));
        actionQuestions = new QAction(MainWindow_teach);
        actionQuestions->setObjectName(QString::fromUtf8("actionQuestions"));
        actionQuestions->setCheckable(true);
        actionStudents_2 = new QAction(MainWindow_teach);
        actionStudents_2->setObjectName(QString::fromUtf8("actionStudents_2"));
        actionStudents_2->setCheckable(true);
        actionStudents_2->setChecked(true);
        actionExit = new QAction(MainWindow_teach);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionLog_out = new QAction(MainWindow_teach);
        actionLog_out->setObjectName(QString::fromUtf8("actionLog_out"));
        actionAllow = new QAction(MainWindow_teach);
        actionAllow->setObjectName(QString::fromUtf8("actionAllow"));
        actionAllow->setCheckable(true);
        actionRefresh = new QAction(MainWindow_teach);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        centralwidget = new QWidget(MainWindow_teach);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(page);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Vertical);
        splitter->setHandleWidth(10);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        formLayout_5 = new QFormLayout(groupBox);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QFont font;
        font.setPointSize(11);
        comboBox->setFont(font);
        comboBox->setEditable(false);

        horizontalLayout_2->addWidget(comboBox);

        pushButton_add = new QPushButton(groupBox);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_add->sizePolicy().hasHeightForWidth());
        pushButton_add->setSizePolicy(sizePolicy2);
        pushButton_add->setFont(font);

        horizontalLayout_2->addWidget(pushButton_add);

        pushButton_rm = new QPushButton(groupBox);
        pushButton_rm->setObjectName(QString::fromUtf8("pushButton_rm"));
        pushButton_rm->setEnabled(false);
        sizePolicy2.setHeightForWidth(pushButton_rm->sizePolicy().hasHeightForWidth());
        pushButton_rm->setSizePolicy(sizePolicy2);
        pushButton_rm->setFont(font);

        horizontalLayout_2->addWidget(pushButton_rm);


        formLayout_5->setLayout(0, QFormLayout::SpanningRole, horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineFN = new QLineEdit(groupBox_3);
        lineFN->setObjectName(QString::fromUtf8("lineFN"));
        lineFN->setFont(font);
        lineFN->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineFN);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineLN = new QLineEdit(groupBox_3);
        lineLN->setObjectName(QString::fromUtf8("lineLN"));
        lineLN->setFont(font);
        lineLN->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineLN);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        lineLogin = new QLineEdit(groupBox_3);
        lineLogin->setObjectName(QString::fromUtf8("lineLogin"));
        lineLogin->setFont(font);
        lineLogin->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineLogin);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_14);

        lineID = new QLineEdit(groupBox_3);
        lineID->setObjectName(QString::fromUtf8("lineID"));
        lineID->setFont(font);
        lineID->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineID);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_10);

        lineRecursion = new QLineEdit(groupBox_4);
        lineRecursion->setObjectName(QString::fromUtf8("lineRecursion"));
        lineRecursion->setFont(font);
        lineRecursion->setReadOnly(true);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineRecursion);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_9);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_11);

        lineStructures = new QLineEdit(groupBox_4);
        lineStructures->setObjectName(QString::fromUtf8("lineStructures"));
        lineStructures->setFont(font);
        lineStructures->setReadOnly(true);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, lineStructures);

        lineFiles = new QLineEdit(groupBox_4);
        lineFiles->setObjectName(QString::fromUtf8("lineFiles"));
        lineFiles->setFont(font);
        lineFiles->setReadOnly(true);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, lineFiles);


        gridLayout->addLayout(formLayout_3, 0, 1, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_4);

        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_12);

        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_13);

        linePointers = new QLineEdit(groupBox_4);
        linePointers->setObjectName(QString::fromUtf8("linePointers"));
        linePointers->setFont(font);
        linePointers->setReadOnly(true);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, linePointers);

        lineDyn_Mem = new QLineEdit(groupBox_4);
        lineDyn_Mem->setObjectName(QString::fromUtf8("lineDyn_Mem"));
        lineDyn_Mem->setFont(font);
        lineDyn_Mem->setReadOnly(true);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineDyn_Mem);

        lineFinal = new QLineEdit(groupBox_4);
        lineFinal->setObjectName(QString::fromUtf8("lineFinal"));
        lineFinal->setFont(font);
        lineFinal->setReadOnly(true);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, lineFinal);


        gridLayout->addLayout(formLayout_4, 0, 5, 1, 1);

        lineMean = new QLineEdit(groupBox_4);
        lineMean->setObjectName(QString::fromUtf8("lineMean"));
        lineMean->setFont(font);
        lineMean->setReadOnly(true);

        gridLayout->addWidget(lineMean, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_6);

        lineLoops = new QLineEdit(groupBox_4);
        lineLoops->setObjectName(QString::fromUtf8("lineLoops"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineLoops->sizePolicy().hasHeightForWidth());
        lineLoops->setSizePolicy(sizePolicy3);
        lineLoops->setFont(font);
        lineLoops->setInputMethodHints(Qt::ImhDigitsOnly);
        lineLoops->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineLoops);

        lineArrays = new QLineEdit(groupBox_4);
        lineArrays->setObjectName(QString::fromUtf8("lineArrays"));
        lineArrays->setFont(font);
        lineArrays->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineArrays);

        lineStrings = new QLineEdit(groupBox_4);
        lineStrings->setObjectName(QString::fromUtf8("lineStrings"));
        lineStrings->setFont(font);
        lineStrings->setReadOnly(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lineStrings);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_8);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_7);


        gridLayout->addLayout(formLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);

        horizontalLayout_3->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout_3, 2, 5, 1, 1);


        horizontalLayout->addWidget(groupBox_4);


        formLayout_5->setLayout(1, QFormLayout::SpanningRole, horizontalLayout);

        splitter->addWidget(groupBox);
        tableWidget = new QTableWidget(splitter);
        if (tableWidget->columnCount() < 12)
            tableWidget->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy4);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSortingEnabled(true);
        tableWidget->setRowCount(1);
        splitter->addWidget(tableWidget);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(90);
        tableWidget->horizontalHeader()->setMinimumSectionSize(35);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(splitter);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_5 = new QGridLayout(page_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        frame = new QFrame(page_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        radioButton_A1 = new QRadioButton(groupBox_2);
        radioButton_A1->setObjectName(QString::fromUtf8("radioButton_A1"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, radioButton_A1);

        radioButton_A2 = new QRadioButton(groupBox_2);
        radioButton_A2->setObjectName(QString::fromUtf8("radioButton_A2"));

        formLayout_6->setWidget(1, QFormLayout::LabelRole, radioButton_A2);

        lineA2 = new QLineEdit(groupBox_2);
        lineA2->setObjectName(QString::fromUtf8("lineA2"));
        lineA2->setFont(font);

        formLayout_6->setWidget(1, QFormLayout::FieldRole, lineA2);

        radioButton_A3 = new QRadioButton(groupBox_2);
        radioButton_A3->setObjectName(QString::fromUtf8("radioButton_A3"));

        formLayout_6->setWidget(2, QFormLayout::LabelRole, radioButton_A3);

        lineA3 = new QLineEdit(groupBox_2);
        lineA3->setObjectName(QString::fromUtf8("lineA3"));
        lineA3->setFont(font);

        formLayout_6->setWidget(2, QFormLayout::FieldRole, lineA3);

        radioButton_A4 = new QRadioButton(groupBox_2);
        radioButton_A4->setObjectName(QString::fromUtf8("radioButton_A4"));

        formLayout_6->setWidget(3, QFormLayout::LabelRole, radioButton_A4);

        lineA4 = new QLineEdit(groupBox_2);
        lineA4->setObjectName(QString::fromUtf8("lineA4"));
        lineA4->setFont(font);

        formLayout_6->setWidget(3, QFormLayout::FieldRole, lineA4);

        lineA1 = new QLineEdit(groupBox_2);
        lineA1->setObjectName(QString::fromUtf8("lineA1"));
        lineA1->setFont(font);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, lineA1);


        verticalLayout_4->addLayout(formLayout_6);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        comboBox_2 = new QComboBox(frame);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy5);
        QFont font2;
        font2.setPointSize(10);
        comboBox_2->setFont(font2);

        horizontalLayout_4->addWidget(comboBox_2);

        comboBox_3 = new QComboBox(frame);
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setFont(font2);

        horizontalLayout_4->addWidget(comboBox_3);

        pushButton_Add_Q = new QPushButton(frame);
        pushButton_Add_Q->setObjectName(QString::fromUtf8("pushButton_Add_Q"));
        sizePolicy5.setHeightForWidth(pushButton_Add_Q->sizePolicy().hasHeightForWidth());
        pushButton_Add_Q->setSizePolicy(sizePolicy5);

        horizontalLayout_4->addWidget(pushButton_Add_Q);

        pushButton_Rem_Q = new QPushButton(frame);
        pushButton_Rem_Q->setObjectName(QString::fromUtf8("pushButton_Rem_Q"));
        sizePolicy5.setHeightForWidth(pushButton_Rem_Q->sizePolicy().hasHeightForWidth());
        pushButton_Rem_Q->setSizePolicy(sizePolicy5);

        horizontalLayout_4->addWidget(pushButton_Rem_Q);


        verticalLayout_2->addLayout(horizontalLayout_4);

        textEdit = new QTextEdit(frame);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setFont(font1);

        verticalLayout_2->addWidget(textEdit);


        gridLayout_4->addLayout(verticalLayout_2, 0, 0, 1, 1);

        pushButton_apply = new QPushButton(frame);
        pushButton_apply->setObjectName(QString::fromUtf8("pushButton_apply"));
        pushButton_apply->setEnabled(false);

        gridLayout_4->addWidget(pushButton_apply, 2, 0, 1, 1);


        gridLayout_5->addWidget(frame, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_5->addItem(verticalSpacer, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_5->addItem(verticalSpacer_2, 2, 2, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout_3->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow_teach->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow_teach);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1133, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        MainWindow_teach->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow_teach);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow_teach->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(lineFN);
        label_3->setBuddy(lineLN);
        label->setBuddy(lineLogin);
        label_14->setBuddy(lineID);
        label_10->setBuddy(lineRecursion);
        label_9->setBuddy(lineStructures);
        label_11->setBuddy(lineFiles);
        label_4->setBuddy(linePointers);
        label_12->setBuddy(lineDyn_Mem);
        label_13->setBuddy(lineFinal);
        label_5->setBuddy(lineMean);
        label_6->setBuddy(lineLoops);
        label_8->setBuddy(lineArrays);
        label_7->setBuddy(lineStrings);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(comboBox, pushButton_add);
        QWidget::setTabOrder(pushButton_add, pushButton_rm);
        QWidget::setTabOrder(pushButton_rm, lineFN);
        QWidget::setTabOrder(lineFN, lineLN);
        QWidget::setTabOrder(lineLN, lineLogin);
        QWidget::setTabOrder(lineLogin, lineID);
        QWidget::setTabOrder(lineID, lineLoops);
        QWidget::setTabOrder(lineLoops, lineArrays);
        QWidget::setTabOrder(lineArrays, lineStrings);
        QWidget::setTabOrder(lineStrings, lineRecursion);
        QWidget::setTabOrder(lineRecursion, lineStructures);
        QWidget::setTabOrder(lineStructures, lineFiles);
        QWidget::setTabOrder(lineFiles, linePointers);
        QWidget::setTabOrder(linePointers, lineDyn_Mem);
        QWidget::setTabOrder(lineDyn_Mem, lineFinal);
        QWidget::setTabOrder(lineFinal, lineMean);
        QWidget::setTabOrder(lineMean, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton);
        QWidget::setTabOrder(pushButton, tableWidget);
        QWidget::setTabOrder(tableWidget, comboBox_2);
        QWidget::setTabOrder(comboBox_2, comboBox_3);
        QWidget::setTabOrder(comboBox_3, pushButton_Add_Q);
        QWidget::setTabOrder(pushButton_Add_Q, pushButton_Rem_Q);
        QWidget::setTabOrder(pushButton_Rem_Q, textEdit);
        QWidget::setTabOrder(textEdit, radioButton_A1);
        QWidget::setTabOrder(radioButton_A1, lineA1);
        QWidget::setTabOrder(lineA1, radioButton_A2);
        QWidget::setTabOrder(radioButton_A2, lineA2);
        QWidget::setTabOrder(lineA2, radioButton_A3);
        QWidget::setTabOrder(radioButton_A3, lineA3);
        QWidget::setTabOrder(lineA3, radioButton_A4);
        QWidget::setTabOrder(radioButton_A4, lineA4);
        QWidget::setTabOrder(lineA4, pushButton_apply);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen_Database);
        menuFile->addSeparator();
        menuFile->addAction(actionClose_Database);
        menuFile->addSeparator();
        menuFile->addAction(actionRefresh);
        menuFile->addSeparator();
        menuFile->addAction(actionLog_out);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addSeparator();
        menuEdit->addAction(actionAllow);
        menuHelp->addAction(actionGet_Help);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);
        menuWindow->addAction(actionStudents_2);
        menuWindow->addAction(actionQuestions);

        retranslateUi(MainWindow_teach);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow_teach);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_teach)
    {
        MainWindow_teach->setWindowTitle(QApplication::translate("MainWindow_teach", "Teacher's mode", nullptr));
        actionOpen_Database->setText(QApplication::translate("MainWindow_teach", "Open Database", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen_Database->setToolTip(QApplication::translate("MainWindow_teach", "<html><head/><body><p>Ctrl + O</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionOpen_Database->setShortcut(QApplication::translate("MainWindow_teach", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionClose_Database->setText(QApplication::translate("MainWindow_teach", "Close Database", nullptr));
        actionGet_Help->setText(QApplication::translate("MainWindow_teach", "Get Help (Online)", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow_teach", "About", nullptr));
        actionAbout_Qt->setText(QApplication::translate("MainWindow_teach", "About Qt", nullptr));
        actionStudents->setText(QApplication::translate("MainWindow_teach", "Students", nullptr));
        actionQuestions->setText(QApplication::translate("MainWindow_teach", "Questions", nullptr));
#ifndef QT_NO_TOOLTIP
        actionQuestions->setToolTip(QApplication::translate("MainWindow_teach", "<html><head/><body><p>Ctrl + 2</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionQuestions->setShortcut(QApplication::translate("MainWindow_teach", "Ctrl+2", nullptr));
#endif // QT_NO_SHORTCUT
        actionStudents_2->setText(QApplication::translate("MainWindow_teach", "Students", nullptr));
#ifndef QT_NO_TOOLTIP
        actionStudents_2->setToolTip(QApplication::translate("MainWindow_teach", "<html><head/><body><p>Ctrl + 1</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionStudents_2->setShortcut(QApplication::translate("MainWindow_teach", "Ctrl+1", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow_teach", "Exit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow_teach", "<html><head/><body><p>Ctrl + Q</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow_teach", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionLog_out->setText(QApplication::translate("MainWindow_teach", "Log out", nullptr));
        actionAllow->setText(QApplication::translate("MainWindow_teach", "Allow editing scores", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAllow->setToolTip(QApplication::translate("MainWindow_teach", "<html><head/><body><p>Ctrl+E</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionAllow->setShortcut(QApplication::translate("MainWindow_teach", "Ctrl+E", nullptr));
#endif // QT_NO_SHORTCUT
        actionRefresh->setText(QApplication::translate("MainWindow_teach", "Refresh students", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRefresh->setToolTip(QApplication::translate("MainWindow_teach", "<html><head/><body><p>Ctrl + R</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionRefresh->setShortcut(QApplication::translate("MainWindow_teach", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        groupBox->setTitle(QString());
        comboBox->setItemText(0, QApplication::translate("MainWindow_teach", "Choose a student...", nullptr));

        comboBox->setCurrentText(QApplication::translate("MainWindow_teach", "Choose a student...", nullptr));
        pushButton_add->setText(QApplication::translate("MainWindow_teach", "+", nullptr));
        pushButton_rm->setText(QApplication::translate("MainWindow_teach", "-", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow_teach", "Credentials", nullptr));
        label_2->setText(QApplication::translate("MainWindow_teach", "First name", nullptr));
        label_3->setText(QApplication::translate("MainWindow_teach", "Last name", nullptr));
        label->setText(QApplication::translate("MainWindow_teach", "Login", nullptr));
        label_14->setText(QApplication::translate("MainWindow_teach", "ID", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow_teach", "Scores", nullptr));
        label_10->setText(QApplication::translate("MainWindow_teach", "Recursion", nullptr));
        label_9->setText(QApplication::translate("MainWindow_teach", "Structures", nullptr));
        label_11->setText(QApplication::translate("MainWindow_teach", "Files", nullptr));
        label_4->setText(QApplication::translate("MainWindow_teach", "Pointers and adresses", nullptr));
        label_12->setText(QApplication::translate("MainWindow_teach", "Dynamic memory", nullptr));
        label_13->setText(QApplication::translate("MainWindow_teach", "Final test result", nullptr));
        label_5->setText(QApplication::translate("MainWindow_teach", "Arithmetic mean of all results", nullptr));
        label_6->setText(QApplication::translate("MainWindow_teach", "Loops", nullptr));
        label_8->setText(QApplication::translate("MainWindow_teach", "Arrays", nullptr));
        label_7->setText(QApplication::translate("MainWindow_teach", "Strings", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow_teach", "Apply changes", nullptr));
        pushButton->setText(QApplication::translate("MainWindow_teach", "Reset all scores", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow_teach", "First name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow_teach", "Last name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow_teach", "Loops", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow_teach", "Arrays", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow_teach", "Strings", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow_teach", "Recursion", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow_teach", "Stuctures", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow_teach", "Files", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow_teach", "Pointers", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow_teach", "Dynamics", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow_teach", "Final test", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow_teach", "Mean", nullptr));
        groupBox_2->setTitle(QString());
        radioButton_A1->setText(QString());
        radioButton_A2->setText(QString());
        radioButton_A3->setText(QString());
        radioButton_A4->setText(QString());
        comboBox_2->setItemText(0, QApplication::translate("MainWindow_teach", "Topic...", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("MainWindow_teach", "Loops", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("MainWindow_teach", "Arrays", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("MainWindow_teach", "Strings", nullptr));
        comboBox_2->setItemText(4, QApplication::translate("MainWindow_teach", "Recursion", nullptr));
        comboBox_2->setItemText(5, QApplication::translate("MainWindow_teach", "Structures", nullptr));
        comboBox_2->setItemText(6, QApplication::translate("MainWindow_teach", "Files", nullptr));
        comboBox_2->setItemText(7, QApplication::translate("MainWindow_teach", "Pointers", nullptr));
        comboBox_2->setItemText(8, QApplication::translate("MainWindow_teach", "Dynamic memory", nullptr));

        comboBox_3->setItemText(0, QApplication::translate("MainWindow_teach", "Question...", nullptr));

        pushButton_Add_Q->setText(QApplication::translate("MainWindow_teach", "+", nullptr));
        pushButton_Rem_Q->setText(QApplication::translate("MainWindow_teach", "-", nullptr));
        pushButton_apply->setText(QApplication::translate("MainWindow_teach", "Apply changes", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow_teach", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow_teach", "Edit", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow_teach", "Help", nullptr));
        menuWindow->setTitle(QApplication::translate("MainWindow_teach", "Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_teach: public Ui_MainWindow_teach {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_TEACH_H
