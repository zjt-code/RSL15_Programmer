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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
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
    QPushButton *BT_WriteParam;
    QLineEdit *lineEdit_SN;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_SensorCode;
    QLabel *label_6;
    QLineEdit *lineEdit_SensorBatch;
    QLabel *label_7;
    QLineEdit *lineEdit_SensorCode_2;
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
        BT_WriteParam = new QPushButton(centralwidget);
        BT_WriteParam->setObjectName(QString::fromUtf8("BT_WriteParam"));
        BT_WriteParam->setGeometry(QRect(590, 180, 93, 28));
        lineEdit_SN = new QLineEdit(centralwidget);
        lineEdit_SN->setObjectName(QString::fromUtf8("lineEdit_SN"));
        lineEdit_SN->setGeometry(QRect(120, 160, 141, 21));
        lineEdit_SN->setToolTipDuration(-1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 160, 51, 21));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(120, 190, 141, 21));
        dateEdit_2 = new QDateEdit(centralwidget);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(120, 220, 141, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 190, 72, 15));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 220, 72, 15));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(300, 200, 72, 15));
        lineEdit_SensorCode = new QLineEdit(centralwidget);
        lineEdit_SensorCode->setObjectName(QString::fromUtf8("lineEdit_SensorCode"));
        lineEdit_SensorCode->setGeometry(QRect(390, 200, 111, 21));
        lineEdit_SensorCode->setToolTipDuration(-1);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(300, 170, 72, 15));
        lineEdit_SensorBatch = new QLineEdit(centralwidget);
        lineEdit_SensorBatch->setObjectName(QString::fromUtf8("lineEdit_SensorBatch"));
        lineEdit_SensorBatch->setGeometry(QRect(390, 170, 111, 21));
        lineEdit_SensorBatch->setToolTipDuration(-1);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(300, 230, 72, 15));
        lineEdit_SensorCode_2 = new QLineEdit(centralwidget);
        lineEdit_SensorCode_2->setObjectName(QString::fromUtf8("lineEdit_SensorCode_2"));
        lineEdit_SensorCode_2->setGeometry(QRect(390, 230, 111, 21));
        lineEdit_SensorCode_2->setToolTipDuration(-1);
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
        BT_WriteParam->setText(QApplication::translate("MainWindow", "\345\206\231\345\205\245\345\217\202\346\225\260", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_SN->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_SN->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("MainWindow", "\345\272\217\345\210\227\345\217\267", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\347\224\237\344\272\247\346\227\245\346\234\237", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\234\211\346\225\210\346\227\245\346\234\237", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\344\274\240\346\204\237\345\231\250\346\240\241\345\207\206\347\240\201", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_SensorCode->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_SensorCode->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_6->setText(QApplication::translate("MainWindow", "\344\274\240\346\204\237\345\231\250\346\211\271\346\254\241", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_SensorBatch->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_SensorBatch->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_7->setText(QApplication::translate("MainWindow", "\347\241\254\344\273\266\347\211\210\346\234\254", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_SensorCode_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_SensorCode_2->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        File->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
