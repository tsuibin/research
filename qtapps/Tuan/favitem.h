#ifndef FAVITEM_H
#define FAVITEM_H

#include <QWidget>
#include <QProcess>
#include <QtWebKit/QWebView>
#include <QDebug>

#include "map.h"

namespace Ui {
    class FavItem;
}

class FavItem : public QWidget
{
    Q_OBJECT

public:
    explicit FavItem(QWidget *parent = 0);
    ~FavItem();
    Qt::CheckState getState();
public slots:
    void openBrowser();
    void openMap();
    void setData(QString picName, QString title, QString price, QString agio, QString url);

private:
    Ui::FavItem *ui;
    QString m_url;
    Map *m_map;
    QWebView *webView;
};

#endif // FAVITEM_H
