#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<libloaderapi.h>
#include <windows.h>
#include "cgms_prm.h"
#include "optiondialog.h"


#define ENABLE_QBUG  1
#define APP_VER  "P3A_Programm_Tool V1.0.1"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool is_SN_OK(QString &sn);
private slots:
    void on_BT_Programm_clicked();
    void on_BT_ChooseFile_clicked();
    void on_BT_WriteParam_clicked();

    void on_actionOpen_triggered();

    void on_actionOption_triggered();
    void on_menuOption_triggered();
    void on_help_triggered();
    void on_optiondialog_accepted();
    void on_optiondialog_rejected();

private:
    Ui::MainWindow *ui;
    OptionDialog *opdialog;
    
    //Define dll handle
    HMODULE hdl_dll;
    QString strLoadFileDir;  
    uint8_t Device_MAC[6];    

};
#endif // MAINWINDOW_H
