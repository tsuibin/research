#include "girdview.h"
#include "ui_girdview.h"

GirdView::GirdView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GirdView)
{
    ui->setupUi(this);
}

GirdView::~GirdView()
{
    delete ui;
}
