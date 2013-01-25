#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
    ui->webView->setUrl(QUrl("http://map.qq.com/"));
}

Map::~Map()
{
    delete ui;
}
