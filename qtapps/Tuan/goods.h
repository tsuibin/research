#ifndef GOODS_H
#define GOODS_H

#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QProcess>

namespace Ui {
    class Goods;
}

class Goods : public QWidget
{
    Q_OBJECT

public:
    explicit Goods(int no = 0, QWidget *parent = 0);
    ~Goods();
    void setData(QString no, QString link,
                 QString price, QString agio,
                 QString url);

    QString getPicName();
    QString getTitle();
    QString getPrice();
    QString getAgio();
    QString getUrl();



public slots:
    void favClick();
    void openBrowser();

signals:
    void favClicked(int);

private:
    Ui::Goods *ui;
    int _no;
    QString m_url;
    static int count;
    QString getPicName(QString picurl);
    QString m_picName;


};

#endif // GOODS_H
