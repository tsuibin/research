/**************************************************************************
**   
**   Special keywords: tsuibin 10/29/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

#include <QThread>
#include <QDebug>

class CaptureThread : public QThread
{
    Q_OBJECT
public:
    explicit CaptureThread(QObject *parent = 0);
    void run();

signals:

public slots:

};

#endif // CAPTURETHREAD_H
