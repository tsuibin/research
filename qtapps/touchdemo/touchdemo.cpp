#include "touchdemo.h"
#include "ui_touchdemo.h"

#include "topmenu.h"
#include "girdview.h"

TouchDemo::TouchDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TouchDemo)
{
    ui->setupUi(this);
    this->setWindowTitle("深度看图");


    QString picPath = "images/bg.jpg";
    ui->label->setPixmap(QPixmap(picPath));


 //   getImgList("/usr/share/wallpapers/kdeepin");

    m_girdView = new GirdView(this);
    m_girdView->show();

    m_topMenu = new TopMenu(this);
    m_topMenu->show();



   // connect(m_topMenu,SIGNAL(testImg()),m_girdView,SLOT(initImg()));
    m_girdView->initImg();


}

TouchDemo::~TouchDemo()
{
    delete m_topMenu;
    delete m_girdView;
    delete ui;
}


