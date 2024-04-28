#include "optiondialog.h"
#include "./ui_optiondialog.h"
#include <iostream>

OptionDialog::OptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionDialog)   
{
    ui->setupUi(this); 
    speed_index = ui->ComBoxSpeed->currentIndex();
    inface_index = ui->ComBoxInterface->currentIndex();


}

OptionDialog::~OptionDialog()
{
    delete ui;
}


Ui::OptionDialog * OptionDialog::OptionDialog_Get_ui()
{    
    return ui;
}





void OptionDialog::on_buttonBox_accepted()
{
    std::cout<<" pressed OK"<<std::endl;
    speed_index = ui->ComBoxSpeed->currentIndex();
    inface_index = ui->ComBoxInterface->currentIndex();
    emit signal_button_ok();

}



void OptionDialog::on_buttonBox_rejected()
{
    std::cout<<" pressed cancelled"<<std::endl;

    ui->ComBoxInterface->setCurrentIndex(inface_index);
    ui->ComBoxSpeed->setCurrentIndex(speed_index);
    emit signal_button_cancell();
}


int OptionDialog::Option_get_speed()
{
        int speed = 50;
        switch(speed_index)
        {
            case 0:
            speed = 100;
            break;
            case 1:
            speed = 200;
            break;
            case 2:
            speed = 500;
            break;
            case 3:
            speed = 800;
            break;
            case 4:
            speed = 1000;
            break;
            case 5:
            speed = 2000;
            break;
            case 6:
            speed = 3000;
            break;
            case 7:
            speed = 4000;
            break;
             case 8:
             speed = 5000;
            break;
            case 9:
            speed = 6000;
            break;
            case 10:
            speed = 7000;
            break;
            default: 
            speed = 50;break;
        }
    return speed ;
}

int  OptionDialog::Option_get_inface()
{

    // if(inface_index)
    // {
    //     return 1;
    // }else 
    //     return 2;

    return (inface_index + 1);

}