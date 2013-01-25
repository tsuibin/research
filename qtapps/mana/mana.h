/**************************************************************************
**   
**   Special keywords: tsuibin 10/30/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#ifndef MANA_H
#define MANA_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>

namespace Ui {
    class Mana;
}

class Mana : public QWidget
{
    Q_OBJECT

public:
    explicit Mana(QWidget *parent = 0);
    ~Mana();
public slots:
    void newConnect();
    void sendMsg();
    void recvMsg();
private:
    Ui::Mana *ui;
    QTcpServer *m_server;
    QTcpSocket *m_tcpSocket ;
    QTcpSocket *tcpSocket;
    bool m_canSendMsg;
};

#endif // MANA_H
