#include "downloadpicture.h"

DownloadPicture::DownloadPicture(QObject *parent) :
    QObject(parent)
{

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(replyFinished(QNetworkReply*)));
    connect(this,SIGNAL(getOnePic()),this,SLOT(getPic()));
}


void DownloadPicture::replyFinished(QNetworkReply *reply)
{

    QByteArray tmp;
    tmp.append(reply->readAll());
    m_pic->write(tmp);
    m_pic->flush();
    m_pic->close();
    m_pic->deleteLater();
    emit getOnePic();

}

void DownloadPicture::downloadPic(int no, QString url)
{
    m_Piclist.insert(no,url);
}

void DownloadPicture::startDownload()
{
    qDebug() <<"startDownload";

    getPic();
}
void DownloadPicture::getPic()
{

    QMapIterator<int, QString> i(m_Piclist);
    QString name;
    name.append("./image/");
    if (i.hasNext()) {
        i.next();
        name.append( getPicName(i.value()) + ".jpeg" );
        m_pic = new QFile( name );
        if ( m_pic->exists() == false ){

            m_pic->open(QIODevice::WriteOnly);
            manager->get(QNetworkRequest(QUrl(QString( i.value() ))));
            this->m_Piclist.remove(i.key());
        }else{
            this->m_Piclist.remove(i.key());
            emit getOnePic();
        }
    }else{
        qDebug() <<"downloadOver";
        emit downloadOver();
    }

}

QString DownloadPicture::getPicName(QString picurl)
{
    int nb,ne;
    QString name_begin = "fid=";
    QString name_end = "\"";

    nb = picurl.indexOf(name_begin);
    ne = picurl.indexOf(name_end,nb+name_begin.size());

    return picurl.mid(nb+name_begin.size(),ne - name_begin.size());
}
