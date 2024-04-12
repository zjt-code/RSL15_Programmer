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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QMenuBar *menubar;
    QMenu *File;
    QMenu *Help;

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
        BT_Programm->setGeometry(QRect(670, 30, 93, 28));
        BT_ChooseFile = new QPushButton(centralwidget);
        BT_ChooseFile->setObjectName(QString::fromUtf8("BT_ChooseFile"));
        BT_ChooseFile->setGeometry(QRect(530, 30, 93, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 30, 71, 21));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 30, 381, 31));
        BT_WriteParam = new QPushButton(centralwidget);
        BT_WriteParam->setObjectName(QString::fromUtf8("BT_WriteParam"));
        BT_WriteParam->setGeometry(QRect(290, 80, 93, 28));
        lineEdit_SN = new QLineEdit(centralwidget);
        lineEdit_SN->setObjectName(QString::fromUtf8("lineEdit_SN"));
        lineEdit_SN->setGeometry(QRect(140, 80, 141, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 80, 51, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        File = new QMenu(menubar);
        File->setObjectName(QString::fromUtf8("File"));
        Help = new QMenu(menubar);
        Help->setObjectName(QString::fromUtf8("Help"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(File->menuAction());
        menubar->addAction(Help->menuAction());
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
        label_2->setText(QApplication::translate("MainWindow", "\345\272\217\345\210\227\345\217\267", nullptr));
        File->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        Help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
