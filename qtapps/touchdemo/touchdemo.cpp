#include "touchdemo.h"
#include "ui_touchdemo.h"

#include "topmenu.h"

TouchDemo::TouchDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TouchDemo)
{
    ui->setupUi(this);
    this->setWindowTitle("深度看图");


    QString picPath = "images/bg.jpg";
    ui->label->setPixmap(QPixmap(picPath));

    TopMenu *topMenu = new TopMenu(this);
    topMenu->show();



}

TouchDemo::~TouchDemo()
{
    delete ui;
}
