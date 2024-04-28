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



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) 
    // , myOptionDialog(new MyOptionDialog)  
    , opdialog(new OptionDialog) 
{

    ui->setupUi(this); 

    this->setWindowTitle(QString(APP_VER));
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);

    // QAction * myHelpAction= new QAction(QStringLiteral("帮助"),this);
    // myHelpAction->setObjectName("myHelp");
    // ui->menubar->addAction(myHelpAction);
    // connect(myHelpAction,&QAction::triggered,this,&MainWindow::on_help_triggered);
   // connect(myHelpAction,SIGNAL(QAction::triggered()),this, SLOT(on_help_triggered()));
    // QMenu * myHelpMenu = ui->menubar->addMenu(QStringLiteral("帮助"));

    // QAction *myHelpAction = ui->menubar->addMenu(myHelpMenu);    

    //connect(ui->Help,SIGNAL(ui->Help->mousePressEvent()), this, SLOT(on_help_triggered()));

    // connect(opdialog,SIGNAL(OptionDialog::signal_button_ok()),this,SLOT(on_optiondialog_accepted()));
    // connect(opdialog,SIGNAL(OptionDialog::signal_button_cancell()),this,SLOT(on_optiondialog_rejected()));
    ui->menubar->addAction(QStringLiteral("选项"),this,SLOT(on_menuOption_triggered()));
    ui->menubar->addAction(QStringLiteral("帮助"),this,SLOT(on_help_triggered()));

    char dir[128];
    _getcwd(dir,128);

    for(uint8_t i=0;i<strlen(dir);i++)
    if(dir[i]=='\\')dir[i]='/';

   // strcat_s(dir,"/JLink_x64.dll");
    strcat_s(dir,"/JLink_x64.dll");
  //  printf("exe dir=%s\r\n",dir);    
    hdl_dll =LoadLibrary(dir);



#if ENABLE_QBUG

    //qDebug(dir);
    //ui->Info_TextBrowser->append(dir);
    if(hdl_dll==NULL)
    {
        ui->Info_TextBrowser->setTextColor(QColor(255,0,0));
        ui->Info_TextBrowser->append("Load DLL Fail !!!");
    }
    // else
    // {
    //     ui->Info_TextBrowser->append("Load Dll OK !!!!");
    // }
#endif

}

MainWindow::~MainWindow()
{
    if(hdl_dll!=NULL)
    FreeLibrary(hdl_dll);
    // delete myOptionDialog;
    delete ui;
    
}


void MainWindow::on_BT_ChooseFile_clicked()
{
// #if ENABLE_QBUG
//     ui->Info_TextBrowser->append("ChooseFile button is pressed");
// #endif

    QStringList myTypeLists;
    myTypeLists<<"Hex Files(*.hex)";
    QFileDialog dialog;
   // dialog.setNameFilters(myTypeLists);
   // int ret =dialog.exec();

    // std::cout<<ret<<std::endl;

    //if(ret==1)
    {
    //    ui->Info_TextBrowser->append(dialog.getOpenFileName());
 
    strLoadFileDir=dialog.getOpenFileName(this,tr("Chose Hex"),"C:/",tr("Hex Files(*.hex)"));
    ui->lineEdit->setText(strLoadFileDir);
    ui->Info_TextBrowser->append(strLoadFileDir);

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

        ui->Info_TextBrowser->append("Speed = " + QString::number(opdialog->Option_get_speed())+"Khz");
        ui->Info_TextBrowser->append("Interface = " + QString::fromStdString(opdialog->Option_get_inface()==1?"SWD":"JTAG"));

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

    // std::cout<<str_sn<<std::endl;
    // printf("%s\r\n",p_char);

    for(uint8_t i=0;i<3;i++)
        if(
            (p_char[i]<'0')||(p_char[i]>'Z')||((p_char[i]>'9')&&(p_char[i]<'A')))
        return false;
    
  
   for(uint8_t i=3;i<7;i++)
    if((p_char[i]<'0')||(p_char[i]>'9'))
     return false;

    m_prm_db.P4.prmWMY[0]=(uint8_t)p_char[0];
    m_prm_db.P4.prmWMY[1]=(uint8_t)p_char[1];
    m_prm_db.P4.prmWMY[2]=(uint8_t)p_char[2];
    m_prm_db.P4.prmWMY[3]=(uint8_t)0;

    m_prm_db.P4.SN=     ((uint16_t)(p_char[3]-'0'))*1000
                    +   ((uint16_t)(p_char[4]-'0'))*100
                    +   ( (uint16_t)(p_char[5]-'0'))*10
                    +   ( (uint16_t)(p_char[6]-'0'))*1;
    // printf("%c,%c,%c,\r\n",p_char[0],p_char[1],p_char[2]);
    // printf("%c,%c,%c,\r\n",m_prm_db.P4.prmWMY[0],m_prm_db.P4.prmWMY[1],m_prm_db.P4.prmWMY[2]);
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
    
 

    if((Q_Str_SN.length()==7)&&is_SN_OK(Q_Str_SN))
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
        int retcmd=JLINKARM_TIF_Select(1);
       
        std::cout<<"JLINKARM_TIF_Select ="<<retcmd<<std::endl;

        JLINKARM_SetSpeed(500);
        
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

#if ENABLE_QBUG
     std::cout<<"sizeof(m_prm_db)"<<sizeof(m_prm_db)<<std::endl;
     std::cout<<"read para flash"<<std::endl;
#endif

    // /**************************read from flash*/
    // int ret_read = JLINKARM_ReadMemEx(PARAM_START_ADDR,sizeof(m_prm_db),(void *)&m_prm_db,4);

    // #if ENABLE_QBUG
    //     std::cout<<"read ret="<<ret_read<<std::endl;
    //     std::cout<<"SN="<<m_prm_db.P4.prmWMY<<(uint32_t)m_prm_db.P4.SN<<std::endl;
    //     dump_mem((unsigned char *)&m_prm_db,sizeof(m_prm_db));

    // #endif
    /********************write to flash********/
       // m_prm_db.P4.SN=9999;
        m_prm_db.P4.prmCrc4=do_crc((uint8_t *)&m_prm_db.P4,sizeof(m_prm_db.P4)-2);

        JLINKARM_BeginDownload(0);   //// Indicates start of flash download
        int32_t ret_write=JLINKARM_WriteMemEx(PARAM_START_ADDR,sizeof(m_prm_db),(void *)&m_prm_db,4);
        std::cout<<"writeMem ret="<<ret_write<<std::endl;

        ret_write = JLINKARM_EndDownload(); //// Indicates end of flash download.
                                            //// DLL will download all data into flash memory

        // uint32_t ret_write =0;
        //ui->Info_TextBrowser->append(QString::number(ret_write));

        if(ret_write>=0)
        {
            ui->Info_TextBrowser->setTextColor(QColor(0,0,255));
            ui->Info_TextBrowser->append("Write Parameters OK");
        }
        else
        {    ui->Info_TextBrowser->setTextColor(QColor(255,0,0));
             ui->Info_TextBrowser->append("Wtite Parameters Fail");
        }
      
      /**************************read from flash*/


       int ret_read = JLINKARM_ReadMemEx(PARAM_START_ADDR,sizeof(m_prm_db),(void *)&m_prm_db,4);
  
    #if ENABLE_QBUG
        dump_mem((unsigned char *)&m_prm_db,sizeof(m_prm_db));
        std::cout<<"read ret="<<ret_read<<std::endl;
        std::cout<<"SN="<<m_prm_db.P4.prmWMY;
        std::cout.width(4);
        std::cout<<(uint32_t)m_prm_db.P4.SN<<std::endl;
    #endif
        char write_sn[128];
        snprintf(write_sn,128,"Writer SN =%s%04d ",m_prm_db.P4.prmWMY,m_prm_db.P4.SN);

        QString q_wtite_sn(write_sn);

        ui->Info_TextBrowser->append(q_wtite_sn);



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

    std::cout<<"Help is toggled" <<std::endl;
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


