/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionOption;
    QWidget *centralwidget;
    QTextBrowser *Info_TextBrowser;
    QPushButton *BT_Programm;
    QPushButton *BT_ChooseFile;
    QLabel *label;
    QLineEdit *lineEdit;
    QSplitter *splitter_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QSplitter *splitter;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout;
    QDateEdit *dateEdit_2;
    QDateEdit *dateEdit;
    QLineEdit *lineEdit_SN;
    QSplitter *splitter_2;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_6;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_SensorBatch;
    QLineEdit *lineEdit_SensorCode;
    QLineEdit *lineEdit_SensorCode_2;
    QPushButton *BT_WriteParam;
    QMenuBar *menubar;
    QMenu *File;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionOption = new QAction(MainWindow);
        actionOption->setObjectName(QString::fromUtf8("actionOption"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Info_TextBrowser = new QTextBrowser(centralwidget);
        Info_TextBrowser->setObjectName(QString::fromUtf8("Info_TextBrowser"));
        Info_TextBrowser->setGeometry(QRect(0, 330, 801, 251));
        BT_Programm = new QPushButton(centralwidget);
        BT_Programm->setObjectName(QString::fromUtf8("BT_Programm"));
        BT_Programm->setGeometry(QRect(590, 30, 93, 28));
        BT_ChooseFile = new QPushButton(centralwidget);
        BT_ChooseFile->setObjectName(QString::fromUtf8("BT_ChooseFile"));
        BT_ChooseFile->setGeometry(QRect(490, 30, 93, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 71, 21));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 30, 381, 31));
        splitter_3 = new QSplitter(centralwidget);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setGeometry(QRect(480, 110, 210, 180));
        splitter_3->setOrientation(Qt::Vertical);
        widget = new QWidget(splitter_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(widget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget1 = new QWidget(splitter);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dateEdit_2 = new QDateEdit(widget1);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));

        verticalLayout->addWidget(dateEdit_2);

        dateEdit = new QDateEdit(widget1);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        verticalLayout->addWidget(dateEdit);

        lineEdit_SN = new QLineEdit(widget1);
        lineEdit_SN->setObjectName(QString::fromUtf8("lineEdit_SN"));
        lineEdit_SN->setToolTipDuration(-1);

        verticalLayout->addWidget(lineEdit_SN);


        horizontalLayout->addLayout(verticalLayout);

        splitter->addWidget(widget1);

        verticalLayout_5->addWidget(splitter);

        splitter_2 = new QSplitter(widget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        widget2 = new QWidget(splitter_2);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_7 = new QLabel(widget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_3->addWidget(label_7);

        label_6 = new QLabel(widget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        splitter_2->addWidget(widget2);
        widget3 = new QWidget(splitter_2);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        verticalLayout_4 = new QVBoxLayout(widget3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        lineEdit_SensorBatch = new QLineEdit(widget3);
        lineEdit_SensorBatch->setObjectName(QString::fromUtf8("lineEdit_SensorBatch"));
        lineEdit_SensorBatch->setToolTipDuration(-1);

        verticalLayout_4->addWidget(lineEdit_SensorBatch);

        lineEdit_SensorCode = new QLineEdit(widget3);
        lineEdit_SensorCode->setObjectName(QString::fromUtf8("lineEdit_SensorCode"));
        lineEdit_SensorCode->setToolTipDuration(-1);

        verticalLayout_4->addWidget(lineEdit_SensorCode);

        lineEdit_SensorCode_2 = new QLineEdit(widget3);
        lineEdit_SensorCode_2->setObjectName(QString::fromUtf8("lineEdit_SensorCode_2"));
        lineEdit_SensorCode_2->setToolTipDuration(-1);

        verticalLayout_4->addWidget(lineEdit_SensorCode_2);

        splitter_2->addWidget(widget3);

        verticalLayout_5->addWidget(splitter_2);

        splitter_3->addWidget(widget);
        BT_WriteParam = new QPushButton(splitter_3);
        BT_WriteParam->setObjectName(QString::fromUtf8("BT_WriteParam"));
        splitter_3->addWidget(BT_WriteParam);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        File = new QMenu(menubar);
        File->setObjectName(QString::fromUtf8("File"));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusBar);

        menubar->addAction(File->menuAction());
        File->addSeparator();
        File->addSeparator();
        File->addAction(actionOpen);
        File->addSeparator();
        File->addAction(actionOption);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
#ifndef QT_NO_WHATSTHIS
        MainWindow->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>\344\275\240\345\245\275</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Alt+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionOption->setText(QApplication::translate("MainWindow", "Option", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOption->setShortcut(QApplication::translate("MainWindow", "Alt+P", nullptr));
#endif // QT_NO_SHORTCUT
        BT_Programm->setText(QApplication::translate("MainWindow", "\347\203\247\345\275\225\347\250\213\345\272\217", nullptr));
        BT_ChooseFile->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\350\267\257\345\276\204", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\345\272\217\345\210\227\345\217\267", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\347\224\237\344\272\247\346\227\245\346\234\237", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\234\211\346\225\210\346\227\245\346\234\237", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_SN->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_SN->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_5->setText(QApplication::translate("MainWindow", "\344\274\240\346\204\237\345\231\250\346\240\241\345\207\206\347\240\201", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\347\241\254\344\273\266\347\211\210\346\234\254", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\344\274\240\346\204\237\345\231\250\346\211\271\346\254\241", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_SensorBatch->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_SensorBatch->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lineEdit_SensorCode->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_SensorCode->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lineEdit_SensorCode_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_SensorCode_2->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        BT_WriteParam->setText(QApplication::translate("MainWindow", "\345\206\231\345\205\245\345\217\202\346\225\260", nullptr));
        File->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
