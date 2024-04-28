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
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_OptionDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *ComBoxSpeed;
    QComboBox *ComBoxInterface;
    QRadioButton *radioButton;

    void setupUi(QDialog *OptionDialog)
    {
        if (OptionDialog->objectName().isEmpty())
            OptionDialog->setObjectName(QString::fromUtf8("OptionDialog"));
        OptionDialog->setWindowModality(Qt::ApplicationModal);
        OptionDialog->resize(394, 189);
        buttonBox = new QDialogButtonBox(OptionDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(40, 130, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        ComBoxSpeed = new QComboBox(OptionDialog);
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
        ComBoxSpeed->setGeometry(QRect(40, 50, 87, 22));
        ComBoxInterface = new QComboBox(OptionDialog);
        ComBoxInterface->addItem(QString());
        ComBoxInterface->addItem(QString());
        ComBoxInterface->setObjectName(QString::fromUtf8("ComBoxInterface"));
        ComBoxInterface->setGeometry(QRect(250, 50, 87, 22));
        radioButton = new QRadioButton(OptionDialog);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(40, 110, 115, 19));

        retranslateUi(OptionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionDialog)
    {
        OptionDialog->setWindowTitle(QApplication::translate("OptionDialog", "Dialog", nullptr));
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

        ComBoxInterface->setItemText(0, QApplication::translate("OptionDialog", "SWD", nullptr));
        ComBoxInterface->setItemText(1, QApplication::translate("OptionDialog", "JTAG", nullptr));

        radioButton->setText(QApplication::translate("OptionDialog", "RadioButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionDialog: public Ui_OptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONDIALOG_H
