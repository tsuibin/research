#include "goods.h"
#include "ui_goods.h"

Goods::Goods(int no, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Goods)
{
    _no = no;
    if ( count == 0)
    {
        qDebug() << "only six item can be created";
        return;
    }
    this->count--;
    ui->setupUi(this);
    ui->l_title->setWordWrap(true);
   // ui->l_pic->setPixmap(QPixmap("./image/tuangou_pic.jpg").scaled(105,70));

   // this->setData("./image/tuangou_pic.jpg","商品信息","$0.00","(0折)","");
    connect(ui->pB_fav,SIGNAL(clicked()),this,SLOT(favClick()));
    connect(ui->pB_buy,SIGNAL(clicked()),this,SLOT(openBrowser()));


}

Goods::~Goods()
{
    this->count = 6;
    delete ui;
}
QString Goods::getPicName(QString picurl)
{
    if (picurl.isEmpty()) return "";
    int nb,ne;
    QString name_begin = "fid=";
    QString name_end = "\"";

    nb = picurl.indexOf(name_begin);
    ne = picurl.indexOf(name_end,nb+name_begin.size());

    return "./image/" + picurl.mid(nb+name_begin.size(),ne - name_begin.size()) + ".jpeg";


}
void Goods::setData(QString picurl, QString title, QString price, QString agio, QString url)
{


    m_picName  = getPicName(picurl);
      qDebug() << "set data" << m_picName;
    if ( m_picName.isEmpty() == false ){
        ui->l_pic->setPixmap(QPixmap(m_picName).scaled(105,70));
    }
    ui->l_title->setText(title);
    ui->l_price->setText(price);
    ui->l_agio->setText(agio);
    this->m_url = url;

}
QString Goods::getUrl()
{
    return this->m_url;
}
QString Goods::getPicName()
{
    return this->m_picName;
}
QString Goods::getTitle()
{
    return ui->l_title->text();
}
QString Goods::getPrice()
{
    return ui->l_price->text();
}
QString Goods::getAgio()
{
    return ui->l_agio->text();
}

void Goods::favClick()
{
    emit favClicked(_no);
}

void Goods::openBrowser()
{
    if( this->m_url.isEmpty() ) return;

    QString program = "/usr/bin/chromium-browser";

    QStringList arguments;
    arguments << this->m_url;

    (new QProcess)->start(program,arguments);
}
