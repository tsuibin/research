#include "touchdemo.h"
#include "ui_touchdemo.h"

TouchDemo::TouchDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TouchDemo)
{
    ui->setupUi(this);
    this->setWindowTitle("深度看图");
}

TouchDemo::~TouchDemo()
{
    delete ui;
}
