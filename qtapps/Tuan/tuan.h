#ifndef TUAN_H
#define TUAN_H

#include <QWidget>
#include <QPushButton>
#include <QNetworkReply>
#include <QTextCodec>
#include <QMap>
#include <QTabWidget>
#include <QFile>

#include <QVBoxLayout>
#include <QRect>

#include "goods.h"
#include "favitem.h"
#include "downloadpicture.h"

#include <QDebug>

#define TAB_BROWSER 0
#define TAB_FAVORITE 1

class Tuan : public QWidget
{
    Q_OBJECT

public:
    explicit Tuan(QWidget *parent = 0);
    ~Tuan();
    QPushButton *pB_btn;
    QTabWidget *tabWidget;
    QWidget *tab_browser;
    QWidget *tab_favorite;

    QVBoxLayout *goodsvbl;
    QVBoxLayout *favsvbl;

public slots:
    void pB_clicked();
    void replyFinished(QNetworkReply*);
    void goodClicked(int no);
    void showGoods();
    void tabChanged(int index);

private:
    QNetworkAccessManager   *manager;
    QList< QMap<QString,QString> > m_goodsInfoList;
    QMap< int ,Goods *> m_goods;
    QMap< int,FavItem *> favList;
    QFile pic;
    void addTabWidget();
    void initUI();
    void addGoods();
    void showFavs();
    void downloadPic();
    void deleteFavoriteItem();
    int m_favItemCounter;
    int m_currentTab;

};

#endif // TUAN_H
