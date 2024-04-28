#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H
#include <QDialog>

namespace Ui {
class OptionDialog;
}

class OptionDialog : public QDialog
{
    Q_OBJECT



public:
    explicit OptionDialog(QWidget *parent = nullptr);
    ~OptionDialog();

    Ui::OptionDialog  *OptionDialog_Get_ui();

    int Option_get_speed();
    int Option_get_inface();


 private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


signals:
    void signal_button_ok();
    void signal_button_cancell();

private:
    Ui::OptionDialog *ui;
    int speed_index,inface_index;
};

#endif // OPTIONDIALOG_H
