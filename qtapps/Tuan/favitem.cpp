#include "favitem.h"
#include "ui_favitem.h"

FavItem::FavItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FavItem)
{
    ui->setupUi(this);
//    webView = new QWebView();
//    webView->setObjectName(QString::fromUtf8("webView"));
//    webView->setGeometry(QRect(10, 10, 697, 550));
    ui->l_title->setWordWrap(true);
    connect(ui->pB_buy,SIGNAL(clicked()),this,SLOT(openBrowser()));
    connect(ui->pB_map,SIGNAL(clicked()),this,SLOT(openMap()));
    ui->pB_buy->setText("购买");
    ui->pB_map->setText("地图");

}

FavItem::~FavItem()
{
    delete ui;
}

void FavItem::openMap()
{
//    webView->setUrl(QUrl("http://map.soso.com/"));
//    webView->show();
}

void FavItem::openBrowser()
{
    if( this->m_url.isEmpty() ) return;

    QString program = "/usr/bin/chromium-browser";

    QStringList arguments;
    arguments << this->m_url;

    (new QProcess)->start(program,arguments);
}


void FavItem::setData(QString picName, QString title, QString price, QString agio, QString url)
{
    qDebug() << "set data" << picName;
    if ( picName.isEmpty() == false ){
        ui->l_pic->setPixmap(QPixmap(picName).scaled(105,70));
    }
    ui->l_title->setText(title);
    ui->l_price->setText(price);
    ui->l_agio->setText(agio);
    this->m_url = url;

}

Qt::CheckState FavItem::getState()
{
    return ui->checkBox->checkState();
}
