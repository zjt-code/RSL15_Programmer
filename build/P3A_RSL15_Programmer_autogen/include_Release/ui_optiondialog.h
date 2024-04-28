/********************************************************************************
** Form generated from reading UI file 'optiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONDIALOG_H
#define UI_OPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionDialog
{
public:
    QDialogButtonBox *buttonBox;
    QRadioButton *radioButton;
    QSplitter *splitter;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *ComBoxSpeed;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *ComBoxInterface;

    void setupUi(QDialog *OptionDialog)
    {
        if (OptionDialog->objectName().isEmpty())
            OptionDialog->setObjectName(QString::fromUtf8("OptionDialog"));
        OptionDialog->setWindowModality(Qt::ApplicationModal);
        OptionDialog->resize(414, 189);
        buttonBox = new QDialogButtonBox(OptionDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(40, 130, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        radioButton = new QRadioButton(OptionDialog);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(40, 110, 115, 19));
        splitter = new QSplitter(OptionDialog);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(120, 50, 196, 21));
        splitter->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        ComBoxSpeed = new QComboBox(widget);
        ComBoxSpeed->addItem(QString());
        ComBoxSpeed->addItem(QString());
        ComBoxSpeed->addItem(QString());
        ComBoxSpeed->addItem(QString());
        ComBoxSpeed->addItem(QString());
        ComBoxSpeed->addItem(QString());
        ComBoxSpeed->addItem(QString());
        ComBoxSpeed->addItem(QString());
        ComBoxSpeed->addItem(QString());
        ComBoxSpeed->addItem(QString());
        ComBoxSpeed->setObjectName(QString::fromUtf8("ComBoxSpeed"));

        horizontalLayout->addWidget(ComBoxSpeed);

        splitter->addWidget(widget);
        widget1 = new QWidget(splitter);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        ComBoxInterface = new QComboBox(widget1);
        ComBoxInterface->addItem(QString());
        ComBoxInterface->addItem(QString());
        ComBoxInterface->setObjectName(QString::fromUtf8("ComBoxInterface"));

        horizontalLayout_2->addWidget(ComBoxInterface);

        splitter->addWidget(widget1);

        retranslateUi(OptionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionDialog)
    {
        OptionDialog->setWindowTitle(QApplication::translate("OptionDialog", "Dialog", nullptr));
        radioButton->setText(QApplication::translate("OptionDialog", "RadioButton", nullptr));
        label->setText(QApplication::translate("OptionDialog", "\351\200\237\345\272\246", nullptr));
        ComBoxSpeed->setItemText(0, QApplication::translate("OptionDialog", "50K", nullptr));
        ComBoxSpeed->setItemText(1, QApplication::translate("OptionDialog", "100K", nullptr));
        ComBoxSpeed->setItemText(2, QApplication::translate("OptionDialog", "200K", nullptr));
        ComBoxSpeed->setItemText(3, QApplication::translate("OptionDialog", "500K", nullptr));
        ComBoxSpeed->setItemText(4, QApplication::translate("OptionDialog", "800K", nullptr));
        ComBoxSpeed->setItemText(5, QApplication::translate("OptionDialog", "1000K", nullptr));
        ComBoxSpeed->setItemText(6, QApplication::translate("OptionDialog", "2000K", nullptr));
        ComBoxSpeed->setItemText(7, QApplication::translate("OptionDialog", "3000K", nullptr));
        ComBoxSpeed->setItemText(8, QApplication::translate("OptionDialog", "4000K", nullptr));
        ComBoxSpeed->setItemText(9, QApplication::translate("OptionDialog", "5000K", nullptr));

        label_2->setText(QApplication::translate("OptionDialog", "\347\203\247\345\275\225\346\216\245\345\217\243", nullptr));
        ComBoxInterface->setItemText(0, QApplication::translate("OptionDialog", "SWD", nullptr));
        ComBoxInterface->setItemText(1, QApplication::translate("OptionDialog", "JTAG", nullptr));

    } // retranslateUi

};

namespace Ui {
    class OptionDialog: public Ui_OptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONDIALOG_H
