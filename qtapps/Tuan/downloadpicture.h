#ifndef DOWNLOADPICTURE_H
#define DOWNLOADPICTURE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QDebug>

class DownloadPicture : public QObject
{
    Q_OBJECT
public:
    explicit DownloadPicture(QObject *parent = 0);
    void downloadPic(int no,QString url);
    void startDownload();

signals:
    void getOnePic();
    void downloadOver();

public slots:
    void replyFinished(QNetworkReply *reply);
    void getPic();
private:
    QNetworkAccessManager *manager;
    QFile *m_pic;
    QMap< int , QString > m_Piclist;
    QString getPicName(QString picurl);

};

#endif // DOWNLOADPICTURE_H
