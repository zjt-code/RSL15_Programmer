#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include "JLink_API_Typedef.h"
#include "direct.h"
#include "myutils.h"
#include "./ui_optiondialog.h"
#include "optiondialog.h"
#include "QAction"
#include "hardware_config.h"
#include <direct.h>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <OpenXLSX.hpp>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) 
    , opdialog(new OptionDialog) 
    , timer(new QTimer)
    , status_lable_speed(new QLabel)
    , status_lable_interface(new QLabel)
    , status_lable_path(new QLabel)
    , status_lable_datetime(new QLabel)
{

    ui->setupUi(this); 
    this->setWindowTitle(QString(APP_VER));
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
 
 /*********************************************/
   // add widgets to  status bar
    status_lable_speed->setText("Speed: " + QString::number(opdialog->Option_get_speed())+"Khz");
    status_lable_speed->setFixedWidth(100);
    ui->statusBar->addWidget(status_lable_speed,0);

    status_lable_interface->setText("Interface:" + QString::fromStdString(opdialog->Option_get_inface()==1?"SWD":"JTAG"));
    status_lable_interface->setFixedWidth(100);
    ui->statusBar->addWidget(status_lable_interface,0);

    status_lable_path->setText("Pah:");
    ui->statusBar->addWidget(status_lable_path,1);

    status_lable_datetime->setText(QDateTime::currentDateTime().toString());
    ui->statusBar->addWidget(status_lable_datetime,0);


    // add memu action
 /*********************************************/




    ui->menubar->addAction(QStringLiteral("选项"),this,SLOT(on_menuOption_triggered()));
    ui->menubar->addAction(QStringLiteral("帮助"),this,SLOT(on_help_triggered()));

    
    
    // get exe path ,convert '\' to '/'
    _getcwd(local_path,_MAX_PATH);   // _getcwd used for windows develop
     for(uint8_t i=0;i<strlen(local_path);i++)
    if(local_path[i]=='\\'  )local_path[i]='/';

    
    char dll_dir[_MAX_PATH];
    memcpy(dll_dir,local_path,_MAX_PATH);    

    // cat dll path
    strcat_s(dll_dir,"/JLink_x64.dll");    
    hdl_dll =LoadLibrary(dll_dir);
    std::cout<<dll_dir<<std::endl;

// The contents of <filesystem> are available only with C++17 or later.
    // std::filesystem::path currPath = std::filesystem::current_path();
    // std::cout<<currPath<<std::endl;  
    if(hdl_dll==NULL)
    {
        ui->Info_TextBrowser->setTextColor(QColor(255,0,0));
        ui->Info_TextBrowser->append("Load DLL Fail !!!");
    }

     
     connect(timer, SIGNAL(timeout()), this, SLOT(on_timeout_handle()));
     timer->start(1000);
    


}

MainWindow::~MainWindow()
{
    if(hdl_dll!=NULL)
    FreeLibrary(hdl_dll);
    
    delete status_lable_speed;
    delete status_lable_interface;
    delete status_lable_path;
    delete status_lable_datetime;


    delete ui;
    delete timer;

    
}


void MainWindow::on_BT_ChooseFile_clicked()
{
// #if ENABLE_QBUG
//     ui->Info_TextBrowser->append("ChooseFile button is pressed");
// #endif

    QStringList myTypeLists;
    myTypeLists<<"Hex Files(*.hex)";
    QFileDialog dialog;
    //if(ret==1)
    {
    //open File to download
        strLoadFileDir=dialog.getOpenFileName(this,tr("Chose Hex"),QString(local_path),tr("Hex Files(*.hex)"));
    
        ui->lineEdit->setText(strLoadFileDir);
        ui->Info_TextBrowser->append(strLoadFileDir);

        status_lable_path->setText(strLoadFileDir);

    }
}


// Choose File directory

void MainWindow::on_BT_Programm_clicked()
{
    qDebug()<<"Programm button is pressed";

    pIntCharCharInt JLINKARM_ExecCommand;
    pBoolVoid       JLINKARM_IsConnected;
    pBoolVoid       JLINKARM_IsOpen;
    pIntVoid        JLINKARM_Connect;
    pCharVoid       JLINKARM_Open;
    pVoidVoid       JLINKARM_SetMaxSpeed,JLINKARM_ResetNoHalt;
    pVoidInt        JLINKARM_SetSpeed;
    pIntCharInt     JLINK_DownloadFile;
    pIntVoid        JLINK_EraseChip;
    pIntVoid        JLINKARM_Reset;
    pIntInt         JLINKARM_TIF_Select;

    std::cout<<" dir len="<<strLoadFileDir.length()<<std::endl;

    if(strLoadFileDir.length()==0)
    {
        ui->Info_TextBrowser->setTextColor(QColor(255,0,0));
        ui->Info_TextBrowser->append("Pls Choose Hex File !!!!");
        return;
    }


    ui->Info_TextBrowser->clear();

    if(hdl_dll!=NULL)
     {
        std::cout<<hdl_dll<<std::endl;

        //int32_t ret= hdl_dll.JLINK_EMU_GetLicenses(buff,256);
        JLINKARM_ExecCommand=(pIntCharCharInt)GetProcAddress(hdl_dll,"JLINKARM_ExecCommand");
        JLINKARM_IsConnected =  (pBoolVoid)GetProcAddress(hdl_dll,"JLINKARM_IsConnected");
        JLINKARM_IsOpen =(pBoolVoid)GetProcAddress(hdl_dll,"JLINKARM_IsOpen");
        JLINKARM_Connect =(pIntVoid)GetProcAddress(hdl_dll,"JLINKARM_Connect");
        JLINKARM_Open = (pCharVoid)GetProcAddress(hdl_dll,"JLINKARM_Open");
        JLINKARM_SetMaxSpeed=(pVoidVoid)GetProcAddress(hdl_dll,"JLINKARM_SetMaxSpeed");

        JLINKARM_SetSpeed = (pVoidInt)GetProcAddress(hdl_dll,"JLINKARM_SetSpeed");

        JLINK_DownloadFile = (pIntCharInt)GetProcAddress(hdl_dll,"JLINK_DownloadFile");

        JLINK_EraseChip =(pIntVoid)GetProcAddress(hdl_dll,"JLINK_EraseChip");

        JLINKARM_Reset  =(pIntVoid)GetProcAddress(hdl_dll,"JLINKARM_Reset");

        JLINKARM_ResetNoHalt=(pVoidVoid)GetProcAddress(hdl_dll,"JLINKARM_ResetNoHalt");
        JLINKARM_TIF_Select =(pIntInt)GetProcAddress(hdl_dll,"JLINKARM_TIF_Select");

        

        if(JLINKARM_Open!=NULL)
        {
            
            printf("Jlinkarm_open=%s\r\n",JLINKARM_Open());
        }

        if(JLINKARM_IsOpen==NULL)
            std::cout<<"JLINKARM_IsOpen=NULL"<<std::endl;
        else
            std::cout<<"JLINKARM_IsOpen="<<(uint32_t)JLINKARM_IsOpen()<<std::endl;

        //set swd speed

        // ui->Info_TextBrowser->append("Speed = " + QString::number(opdialog->Option_get_speed())+"Khz");
        // ui->Info_TextBrowser->append("Interface = " + QString::fromStdString(opdialog->Option_get_inface()==1?"SWD":"JTAG"));

        JLINKARM_SetSpeed(opdialog->Option_get_speed());
        //select device
        int retcmd=JLINKARM_ExecCommand("Device=RSL15-512",NULL,0);
        std::cout<<"set name ret="<<retcmd<<std::endl;

        //select SWD 
        retcmd=JLINKARM_TIF_Select(opdialog->Option_get_inface());
       
        std::cout<<"JLINKARM_TIF_Select ="<<retcmd<<std::endl;
       
        //JLINKARM_SetMaxSpeed();
        std::cout<<"JLINLARM_Connect ="<<JLINKARM_Connect()<<std::endl;

        // if(JLINKARM_IsConnected==NULL)
        // std::cout<<"JLinkARM_IsConnected=NULL"<<std::endl;
        // else
        // std::cout<<"JLinkARM_IsConnected="<<(uint32_t)JLINKARM_IsConnected()<<std::endl;


        int ret=JLINK_EraseChip();
        std::cout<<"JLINKARM_Erase All="<<ret<<std::endl;

      
        if(JLINK_DownloadFile!=NULL)
        {
            std::string sdir=strLoadFileDir.toStdString();

            ret = JLINK_DownloadFile(sdir.c_str(),RSL15_512_FLASH_START_ADDR);
            std::cout<<"JLINK_DownloadFile ="<<ret<<std::endl;

            if(ret>=0)
            {
                ui->Info_TextBrowser->setTextColor(QColor(0,0,255));
                ui->Info_TextBrowser->append("Programm Down Load OK!!");
            }
            else
            {
                ui->Info_TextBrowser->setTextColor(QColor(255,0,0));
                ui->Info_TextBrowser->append("Programm Down Load Fail ");
            }
        }
        else
        std::cout<<"JLINK_DownloadFile =NULL"<<std::endl;

    
        if(JLINKARM_ResetNoHalt==NULL)
        { 
            std::cout<<"JLINKARM_ResetNoHalt=NULL"<<std::endl;
           
        }
        else
        {
          JLINKARM_ResetNoHalt();
            ui->Info_TextBrowser->setTextColor(QColor(0,0,255));
           ui->Info_TextBrowser->append(QString("Reset Mcu =")+QString::number(1));
        }

    
     }
     else
     {
        ui->Info_TextBrowser->setTextColor(QColor(255,0,0));
        ui->Info_TextBrowser->append("Hdl is invalide");

     }

      
}

bool MainWindow::is_SN_OK( QString &SN)
{
    std::string str_sn = SN.toStdString();
    const char * p_char = str_sn.c_str();

    // SN Start char "D3-"

    if(p_char[0]!='D' || p_char[1]!= '3' || p_char[2] !='-')
    return false;
    
  
    for(uint8_t i=3; i<SN_LEN; i++)
    {
        if((p_char[i]<'0')||(p_char[i]>'9'))
        return false;
    }

    memcpy(g_factory_config.sn_buffer,p_char,SN_LEN);

    return true;
}

void MainWindow::on_BT_WriteParam_clicked()
{
// #if ENABLE_QBUG
//      ui->Info_TextBrowser->append("on_BT_WriteParam_clicked");
// #endif

    pIntCharCharInt JLINKARM_ExecCommand;
    pBoolVoid       JLINKARM_IsConnected;
    pBoolVoid       JLINKARM_IsOpen;
    pIntVoid        JLINKARM_Connect;
    pCharVoid       JLINKARM_Open;
    pVoidVoid       JLINKARM_SetMaxSpeed,JLINKARM_ResetNoHalt;
    pVoidInt        JLINKARM_SetSpeed,JLINKARM_BeginDownload;
    pIntVoid        JLINKARM_EndDownload;       
   // pVoidU8         JLINKARM_ResetPullsTRST,JLINKARM_ResetPullsRESET;
    //pIntIntIntVoid  JLINKARM_ReadMem,JLINKARM_WriteMem;

    pIntIntIntVoidInt JLINKARM_ReadMemEx,JLINKARM_WriteMemEx;
    pIntInt         JLINKARM_TIF_Select;

    QString Q_Str_SN = ui->lineEdit_SN->text();
    
 

    if((Q_Str_SN.length()==SN_LEN)&&is_SN_OK(Q_Str_SN))
    {
        //ui->Info_TextBrowser->append(Q_Str_SN);


    if(hdl_dll!=NULL)
     {
        std::cout<<hdl_dll<<std::endl;

        //int32_t ret= hdl_dll.JLINK_EMU_GetLicenses(buff,256);
        JLINKARM_ExecCommand=(pIntCharCharInt)GetProcAddress(hdl_dll,"JLINKARM_ExecCommand");
        JLINKARM_IsConnected =  (pBoolVoid)GetProcAddress(hdl_dll,"JLINKARM_IsConnected");
        JLINKARM_IsOpen =(pBoolVoid)GetProcAddress(hdl_dll,"JLINKARM_IsOpen");
        JLINKARM_Connect =(pIntVoid)GetProcAddress(hdl_dll,"JLINKARM_Connect");
        JLINKARM_Open = (pCharVoid)GetProcAddress(hdl_dll,"JLINKARM_Open");
        JLINKARM_SetMaxSpeed=(pVoidVoid)GetProcAddress(hdl_dll,"JLINKARM_SetMaxSpeed");

        JLINKARM_SetSpeed = (pVoidInt)GetProcAddress(hdl_dll,"JLINKARM_SetSpeed"); 

        JLINKARM_ResetNoHalt=(pVoidVoid)GetProcAddress(hdl_dll,"JLINKARM_ResetNoHalt");
      //  JLINKARM_ReadMem    =(pIntIntIntVoid)GetProcAddress(hdl_dll,"JLINKARM_ReadMem");
        JLINKARM_WriteMemEx =(pIntIntIntVoidInt)GetProcAddress(hdl_dll,"JLINKARM_WriteMemEx");
        JLINKARM_ReadMemEx  =(pIntIntIntVoidInt)GetProcAddress(hdl_dll,"JLINKARM_ReadMemEx");
        
        JLINKARM_BeginDownload =(pVoidInt)GetProcAddress(hdl_dll,"JLINKARM_BeginDownload");
        JLINKARM_EndDownload  =(pIntVoid)GetProcAddress(hdl_dll,"JLINKARM_EndDownload");
        JLINKARM_TIF_Select =(pIntInt)GetProcAddress(hdl_dll,"JLINKARM_TIF_Select");

        if(JLINKARM_Open!=NULL)
        {
            
            printf("Jlinkarm_open=%s\r\n",JLINKARM_Open());
        }

        if(JLINKARM_IsOpen==NULL)
            std::cout<<"JLINKARM_IsOpen=NULL"<<std::endl;
        else
            std::cout<<"JLINKARM_IsOpen="<<(uint32_t)JLINKARM_IsOpen()<<std::endl;

        //select device
        JLINKARM_ExecCommand("Device=RSL15-512",NULL,0);

        //JLINKARM_SetMaxSpeed();
        int retcmd=JLINKARM_TIF_Select(opdialog->Option_get_inface());
       
        std::cout<<"JLINKARM_TIF_Select ="<<retcmd<<std::endl;

        JLINKARM_SetSpeed(opdialog->Option_get_speed());
        
        std::cout<<"JLINLARM_Connect ="<<JLINKARM_Connect()<<std::endl;

        if(JLINKARM_IsConnected==NULL)
        std::cout<<"JLinkARM_IsConnected=NULL"<<std::endl;
        else
        std::cout<<"JLinkARM_IsConnected="<<(uint32_t)JLINKARM_IsConnected()<<std::endl;




     }
    else
    {
        ui->Info_TextBrowser->append(QFont("Hdl_dll is invalide").toString());
    }

    // /**************************read from flash*/
    // int ret_read = JLINKARM_ReadMemEx(PARAM_START_ADDR,sizeof(m_prm_db),(void *)&m_prm_db,4);    // #endif
    /********************write to flash********/
    
        JLINKARM_BeginDownload(0);   //// Indicates start of flash download
        int32_t ret_write=JLINKARM_WriteMemEx(FLASH_ADDR_CONFIG,sizeof(factory_config_t),(void *)&g_factory_config,4);
        std::cout<<"writeMem ret="<<ret_write<<std::endl;
        ret_write = JLINKARM_EndDownload(); //// Indicates end of flash download.
                                            //// DLL will download all data into flash memory

        // uint32_t ret_write =0;
        //ui->Info_TextBrowser->append(QString::number(ret_write));

        // if(ret_write>=0)
        // {
           ui->Info_TextBrowser->setTextColor(QColor(0,0,255));
        //     ui->Info_TextBrowser->append("Write Parameters OK");
        // }
        // else
        // {    ui->Info_TextBrowser->setTextColor(QColor(255,0,0));
        //      ui->Info_TextBrowser->append("Wtite Parameters Fail");
        // }
      
      /**************************read from flash*/

        factory_config_t g_readback;


       int ret_read = JLINKARM_ReadMemEx(FLASH_ADDR_CONFIG,sizeof(factory_config_t),(void *)&g_readback,4);
  
    #if ENABLE_QBUG
        dump_mem((unsigned char *)&g_factory_config,sizeof(factory_config_t));
        dump_mem((unsigned char *)&g_readback,sizeof(factory_config_t));
        std::cout<<"read ret="<<ret_read<<std::endl;
        std::cout<<"SN="<<g_readback.sn_buffer;
        std::cout.width(14);
        std::cout<<std::endl;
       
    #endif
        // char write_sn[128];
        // snprintf(write_sn,128,"Writer SN =%s%04d ",m_prm_db.P4.prmWMY,m_prm_db.P4.SN);

        QString q_wtite_sn((char *)g_readback.sn_buffer);

        ui->Info_TextBrowser->append(q_wtite_sn); 

        if(!memcmp((void *)&g_factory_config,(void *)&g_readback,sizeof(factory_config_t)))
        {   ui->Info_TextBrowser->setTextColor(QColor(0,0,255));
            ui->Info_TextBrowser->append("Write successfully");}
        else{
             ui->Info_TextBrowser->setTextColor(QColor(255,0,0));
            ui->Info_TextBrowser->append("Write Fail");}

    /***Read MAC Address*/ 
        ret_read = JLINKARM_ReadMemEx(MNVR_ADDR,6,(void *)Device_MAC,1);
        std::cout<<"read ret="<<ret_read<<std::endl;
        dump_mem((unsigned char *)&Device_MAC,6);
        char mac_str[18];

        snprintf(mac_str,18,"%02x:%02x:%02x:%02x:%02x:%02x",Device_MAC[5],Device_MAC[4],
                                Device_MAC[3],Device_MAC[2],Device_MAC[1],Device_MAC[0]);

        QString Mac_std_str=QString::fromLocal8Bit("Chip MAC Addr=") + QString::fromLocal8Bit(mac_str);

        ui->Info_TextBrowser->append(Mac_std_str);
    
    /*************/
      if(JLINKARM_ResetNoHalt==NULL)
        { 
            std::cout<<"JLINKARM_ResetNoHalt=NULL"<<std::endl;
        }
        else
        {
          JLINKARM_ResetNoHalt();
           // std::cout<<"JLINKARM_Reset = "<<ret<<std::endl;
        }

    }
    else{
        ui->Info_TextBrowser->append("SN Formate error !!!!");
    }
}

void MainWindow::on_actionOpen_triggered()
{
     ui->Info_TextBrowser->append("action open triggered!");
}

void MainWindow::on_actionOption_triggered()
{
      ui->Info_TextBrowser->append("action Option triggered!");
}



void MainWindow::on_help_triggered()
{
     QMessageBox helpMessage(QMessageBox::Icon::Information, "Thanks QT v5.12", "This windows program is used Jlink driver, ", 
                 QMessageBox::NoButton, nullptr, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

 
// QMessageBox *helpMessage = new QMessageBox(QMessageBox::Icon::Information, "Thanks QT v5.12", "This windows program is used Jlink driver, ", 
//                  QMessageBox::NoButton, nullptr, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
//     helpMessage->show();

    std::cout<<"Help Message box is end ="<<helpMessage.exec()<<std::endl;

    
   
}
void MainWindow::on_menuOption_triggered()
{
    ui->Info_TextBrowser->append("on_menuOption_triggered ");      
    
   // myOptionDialog->show();

    // opdialog->

    // OptionDialog * a = new OptionDialog();
    // a->show();

     opdialog->show();

     Ui::OptionDialog * a = opdialog->OptionDialog_Get_ui();
     
     //opdialog.

   /// OptionDialog *a = myOptionDialog->OptionDialog_Get_ui();

    

        std::cout<< a->ComBoxSpeed->count()<<std::endl;
        std::cout<< a->ComBoxInterface->count()<<std::endl;  


        std::cout<<"speed = "<<a->ComBoxSpeed->currentIndex()<<" ";
        std::cout<<a->ComBoxSpeed->currentText().toStdString()<<std::endl;


        std::cout<<"Interface = "<<a->ComBoxInterface->currentIndex()<<" ";
        std::cout<<a->ComBoxInterface->currentText().toStdString()<<std::endl;

       std::cout<<"myOptionDialog end " <<std::endl;

      

}

void MainWindow::on_optiondialog_accepted()
{
    std::cout<<"optiondialog OK is pressed"<<std::endl;

}

void MainWindow::on_optiondialog_rejected()
{

    std::cout<<"optiondialog cancelled is pressed"<<std::endl;


}

void MainWindow::on_timeout_handle()
{

    status_lable_datetime->setText(QDateTime::currentDateTime().toString());
    // std::cout<<"Timeout 1s "<<std::endl;
}



// using namespace OpenXLSX;

void MainWindow::on_pb_readFlash_clicked()
{
    pIntCharCharInt JLINKARM_ExecCommand;
    pBoolVoid       JLINKARM_IsConnected;
    pBoolVoid       JLINKARM_IsOpen;
    pIntVoid        JLINKARM_Connect;
    pCharVoid       JLINKARM_Open;
    pVoidVoid       JLINKARM_SetMaxSpeed,JLINKARM_ResetNoHalt;
    pVoidInt        JLINKARM_SetSpeed,JLINKARM_BeginDownload;
    pIntVoid        JLINKARM_EndDownload;       
   // pVoidU8         JLINKARM_ResetPullsTRST,JLINKARM_ResetPullsRESET;
    //pIntIntIntVoid  JLINKARM_ReadMem,JLINKARM_WriteMem;

    pIntIntIntVoidInt JLINKARM_ReadMemEx,JLINKARM_WriteMemEx;
    pIntInt         JLINKARM_TIF_Select;


    if(hdl_dll!=NULL)
     {
        std::cout<<hdl_dll<<std::endl;

        //int32_t ret= hdl_dll.JLINK_EMU_GetLicenses(buff,256);
        JLINKARM_ExecCommand=(pIntCharCharInt)GetProcAddress(hdl_dll,"JLINKARM_ExecCommand");
        JLINKARM_IsConnected =  (pBoolVoid)GetProcAddress(hdl_dll,"JLINKARM_IsConnected");
        JLINKARM_IsOpen =(pBoolVoid)GetProcAddress(hdl_dll,"JLINKARM_IsOpen");
        JLINKARM_Connect =(pIntVoid)GetProcAddress(hdl_dll,"JLINKARM_Connect");
        JLINKARM_Open = (pCharVoid)GetProcAddress(hdl_dll,"JLINKARM_Open");
        JLINKARM_SetMaxSpeed=(pVoidVoid)GetProcAddress(hdl_dll,"JLINKARM_SetMaxSpeed");

        JLINKARM_SetSpeed = (pVoidInt)GetProcAddress(hdl_dll,"JLINKARM_SetSpeed"); 

        JLINKARM_ResetNoHalt=(pVoidVoid)GetProcAddress(hdl_dll,"JLINKARM_ResetNoHalt");
      //  JLINKARM_ReadMem    =(pIntIntIntVoid)GetProcAddress(hdl_dll,"JLINKARM_ReadMem");
        JLINKARM_WriteMemEx =(pIntIntIntVoidInt)GetProcAddress(hdl_dll,"JLINKARM_WriteMemEx");
        JLINKARM_ReadMemEx  =(pIntIntIntVoidInt)GetProcAddress(hdl_dll,"JLINKARM_ReadMemEx");
        
        JLINKARM_BeginDownload =(pVoidInt)GetProcAddress(hdl_dll,"JLINKARM_BeginDownload");
        JLINKARM_EndDownload  =(pIntVoid)GetProcAddress(hdl_dll,"JLINKARM_EndDownload");
        JLINKARM_TIF_Select =(pIntInt)GetProcAddress(hdl_dll,"JLINKARM_TIF_Select");

        if(JLINKARM_Open!=NULL)
        {
            
            printf("Jlinkarm_open=%s\r\n",JLINKARM_Open());
        }

        if(JLINKARM_IsOpen==NULL)
            std::cout<<"JLINKARM_IsOpen=NULL"<<std::endl;
        else
            std::cout<<"JLINKARM_IsOpen="<<(uint32_t)JLINKARM_IsOpen()<<std::endl;

        //select device
        JLINKARM_ExecCommand("Device=RSL15-512",NULL,0);

        //JLINKARM_SetMaxSpeed();
        int retcmd=JLINKARM_TIF_Select(opdialog->Option_get_inface());
       
        std::cout<<"JLINKARM_TIF_Select ="<<retcmd<<std::endl;

        JLINKARM_SetSpeed(opdialog->Option_get_speed());
        
        std::cout<<"JLINLARM_Connect ="<<JLINKARM_Connect()<<std::endl;

        if(JLINKARM_IsConnected==NULL)
        std::cout<<"JLinkARM_IsConnected=NULL"<<std::endl;
        else
        std::cout<<"JLinkARM_IsConnected="<<(uint32_t)JLINKARM_IsConnected()<<std::endl;




     }
    else
    {
        ui->Info_TextBrowser->append(QFont("Hdl_dll is invalide").toString());
    }

      uchar red_bff[16];
      int gluc_offset = 0;
      int gluc = 0;  
      int gluc_curr = 0;

        std::string path_cur="./new_cur_I0.xlsx";
        OpenXLSX::XLDocument doc,doc_cur;
        doc_cur.create(path_cur);
        auto wks_cur = doc_cur.workbook().worksheet("Sheet1");

        wks_cur.cell("A1").value() = "I0_Index";
        wks_cur.cell("B1").value() = "I0_Value";
        wks_cur.cell("C1").value() = "I5_Value";
        wks_cur.cell("D1").value() = "Gluco";


      
      for(int x=0; x< 6720; x++)

     {
         int ret_read = JLINKARM_ReadMemEx(FLASHDATA_MAIN_BASE + x *16,16,(void *)red_bff,4);

        gluc_offset = red_bff[1] + ((int)red_bff[2]<<8);
        gluc = red_bff[3] + ((int)red_bff[4]<<8);
        gluc_curr = red_bff[7] + ((int)red_bff[8]<<8);


           std::string doc_cur_i0_index_cell_name="A"+std::to_string(x+2);
           std::string doc_cur_io_value_cell_name="B"+std::to_string(x+2);
           std::string doc_cur_i5_value_cell_name="C"+std::to_string(x+2);
          //string doc_cur_glucose_value_cell_name="D"+std::to_string(s+2);



           std::cout<< gluc_offset <<","<<gluc<< ","<<gluc_curr<<std::endl;

            wks_cur.cell(doc_cur_i0_index_cell_name).value() = gluc_offset;
            wks_cur.cell(doc_cur_io_value_cell_name).value() = (float)gluc_curr/100.0f;
            wks_cur.cell(doc_cur_i5_value_cell_name).value() = (float)gluc/10.0f;
    

     }
      

       doc_cur.save();
       doc_cur.close();

    // #if ENABLE_QBUG
    //     dump_mem((unsigned char *)&red_bff[0],sizeof(red_bff));

    // #endif

        std::cout<<"button readFlash is pressed\r\n"<<std::endl;

}
