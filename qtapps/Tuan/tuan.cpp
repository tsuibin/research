#include "tuan.h"

Tuan::Tuan(QWidget *parent) :
    QWidget(parent)
{
    this->resize(500,600);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(replyFinished(QNetworkReply*)));

    this->m_favItemCounter = 0;
    initUI();
    addTabWidget();
    addGoods();
    pB_clicked();

}

Tuan::~Tuan()
{
    qDebug() <<"~Tuan";

}
void Tuan::initUI()
{
    QLabel *logo = new QLabel(this);
    logo->setPixmap(QPixmap("./image/logo_100x100.gif").scaled(70,70));
    logo->setGeometry(10,5,100,100);

    QLabel *title = new QLabel(this);
    title->setText("搜搜团购收藏夹");
    title->setGeometry(100,30,300,50);
    title->setStyleSheet("font: 28pt \"宋体\";");

    //get data button
    pB_btn = new QPushButton(this);
    pB_btn->setGeometry(400,79,88,21);
    pB_btn->setText("Update");

    connect(pB_btn,SIGNAL(clicked()),this,SLOT(pB_clicked()));
}
/*
this is define value
TAB_BROWSER 0
TAB_FAVORITE 1
*/
void Tuan::tabChanged(int index)
{
    qDebug() <<"tabChanged"<< index;
    switch(index)
    {
    case TAB_BROWSER:
        m_currentTab = TAB_BROWSER;
        //show broeser button
        break;

    case TAB_FAVORITE:
        m_currentTab = TAB_FAVORITE;
        //show favorite button
        break;

    default:break;

    }
}
void Tuan::addTabWidget()
{
    //tab widget
    tabWidget = new QTabWidget(this);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setGeometry(QRect(10, 95, 480, 480));
    connect(tabWidget,SIGNAL(currentChanged(int)),this,SLOT(tabChanged(int)));

    //browser
    tab_browser = new QWidget();
    tab_browser->setObjectName(QString::fromUtf8("tab_browser"));
    tabWidget->addTab(tab_browser, QString("browser"));

    //favorite
    tab_favorite = new QWidget();
    tab_favorite->setObjectName(QString::fromUtf8("tab_favorite"));
    tabWidget->addTab(tab_favorite, QString("favorite"));



    //goodsvbl = new QVBoxLayout(tab_browser);
    //favsvbl = new QVBoxLayout(tab_favorite);
}
void Tuan::pB_clicked()
{
    qDebug() <<"pB_clicked";

    switch(m_currentTab)
    {
    case TAB_BROWSER:
        //send request
        manager->get(QNetworkRequest(QUrl("http://tuan.soso.com/")));
        break;

    case TAB_FAVORITE:
        //delete item
        deleteFavoriteItem();
        break;

    default:break;

    }

}
void Tuan::deleteFavoriteItem()
{
    qDebug() << "deleteFavoriteItem" << favList;
    QList<int> favkeys = favList.keys();
    for (int i = 0; i < favkeys.size() ; i++)
    {
        FavItem *fav = favList.value(favkeys.at(i));
        if ( Qt::Checked == fav->getState() )
        {
            favList.remove(favkeys.at(i));
            delete fav;
        }
    }

    //fav count --
    //fav view update
    //


    //checkState
}
void Tuan::goodClicked(int no)
{
    qDebug() <<"goodClicked";
    // show current good item
    if (this->m_favItemCounter < 6)
    {
        Goods *good = this->m_goods.value(no);
        //add to favorite widget
        qDebug() <<"shou"<< this->m_favItemCounter;
        FavItem *favItem = new FavItem(tab_favorite);
        favItem->setGeometry(0, this->m_favItemCounter * 75,470,80);
        favItem->setData(good->getPicName()
                     ,good->getTitle()
                     ,good->getPrice()
                     ,good->getAgio()
                     ,good->getUrl());
        favList.insert(no,favItem);
        this->m_favItemCounter++;
    }else{
        //show next button
    }
}

void Tuan::showFavs()
{
    qDebug() <<"showFavs";
}

void Tuan::downloadPic()
{
    qDebug() <<"downloadPic";
    DownloadPicture *dp = new DownloadPicture;
    connect(dp,SIGNAL(downloadOver()),this,SLOT(showGoods()));
    for(int i = 0; i < m_goodsInfoList.size(); i++){

        dp->downloadPic(m_goodsInfoList.at(i).value("no").toInt(),
                       m_goodsInfoList.at(i).value("picurl"));
    }
    dp->startDownload();
}

void Tuan::addGoods()
{
    qDebug() << "addGoods";
    for (int i = 0,y = 0; i < 6; i++,y+=75)
    {
        qDebug() << y;
       Goods *good = new Goods(i,tab_browser);
       if ( good == NULL ){
           qDebug() << "good is null";
           return;
       }
       good->setGeometry(0,y,470,80);
       m_goods.insert(i,good);
       connect(good,SIGNAL(favClicked(int)),this,SLOT(goodClicked(int)));

    }
}

void Tuan::showGoods()
{
    qDebug() <<"showGoods";


    for(int i = 0; i < 6 && i < this->m_goodsInfoList.size(); i++)
    {
        Goods *good = this->m_goods.value(i);

        good->setData(
                this->m_goodsInfoList.at(i).value("picurl"),
                this->m_goodsInfoList.at(i).value("title"),
                this->m_goodsInfoList.at(i).value("sale"),
                this->m_goodsInfoList.at(i).value("agio"),
                this->m_goodsInfoList.at(i).value("url")
                );
        good->show();
    }
}

void Tuan::replyFinished(QNetworkReply *reply)
{
    qDebug() <<"replyFinished";

    QTextCodec* gbk_codec = QTextCodec::codecForName("gb2312");
    QString html = gbk_codec->toUnicode(reply->readAll().data());

    int f = 0;
    int l = 0;
    int pics = 0;

    QString seller_begin = "<cite class=\"seller\">";
    QString seller_end = "</cite>";
    QString url_begin = "href=\"";
    QString url_end = "\"";

    QString pic_start = "<div class=\"image\">";
    QString pic_begin = "src=\"";
    QString pic_end = "\"";

    QString title_begin = ">";
    QString title_end = "<";
    QString stat_begin = "<p class=\"stat\">";
    QString stat_end = "</p>";
    QString orig_price_begin = "<span class=\"orig_price\">";
    QString orig_price_end = "</span>";
    QString agio_begin = "<span class=\"agio\">";
    QString agio_end = "</span>";
    QString area_begin = "<p class=\"area\">";
    QString area_end = "</p>";
    QString sale_begin = "<em class=\"count\">";
    QString sale_end = "</em>";


    for(int i = 0; i < html.size(); i++)
    {
        QMap<QString,QString> m_goodInfo;

        f = html.indexOf(seller_begin,f+1);
        l =  html.indexOf(seller_end,l+ seller_begin.size());
        if (f < 0 || l < 0) break;

        m_goodInfo.insert("seller",html.mid(f+seller_begin.size(),l-f-seller_begin.size()));

        int ub = html.indexOf(url_begin,l + seller_end.size() );
        int ue = html.indexOf(url_end,ub+ url_begin.size());

        m_goodInfo.insert("url","http://tuan.soso.com" + html.mid(ub+url_begin.size(),ue-ub-url_begin.size()));

        pics = html.indexOf(pic_start, pics + pic_start.size());
        int picb = html.indexOf(pic_begin,pics + pic_start.size() );
        int pice = html.indexOf(pic_end,picb+ pic_begin.size());
       m_goodInfo.insert("picurl", html.mid(picb+pic_begin.size(),pice-picb-pic_begin.size()));

        int tb = html.indexOf(title_begin,l + seller_end.size() );
        int te = html.indexOf(title_end,tb + title_begin.size() );

      m_goodInfo.insert("title",html.mid(tb + title_begin.size() , te - tb - title_begin.size()));

        int sb = html.indexOf(stat_begin,te + title_end.size() );
        int se = html.indexOf(stat_end,sb + stat_begin.size());

      m_goodInfo.insert("stat",html.mid(sb + stat_begin.size() , se - sb - stat_begin.size()) );

        int pb = html.indexOf(orig_price_begin,se + stat_end.size() );
        int pe = html.indexOf(orig_price_end,pb + orig_price_begin.size() );

        m_goodInfo.insert("price",html.mid(pb + orig_price_begin.size() , pe - pb - orig_price_begin.size()));

        int ab = html.indexOf(agio_begin,pe + orig_price_end.size());
        int ae = html.indexOf(agio_end,ab + agio_begin.size());
        m_goodInfo.insert("agio",html.mid( ab + agio_begin.size() , ae - ab - agio_begin.size() ));

        int sab = html.indexOf(sale_begin,ae + agio_end.size());
        int sae = html.indexOf(sale_end,sab + sale_begin.size());
   m_goodInfo.insert("sale",html.mid(sab + sale_begin.size() , sae - sab - sale_begin.size() ) );

        m_goodInfo.insert("no",QString::number(i));


        m_goodsInfoList.append( m_goodInfo );



    }
    downloadPic();
}
