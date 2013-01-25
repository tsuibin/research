/**************************************************************************
**   
**   Special keywords: tsuibin 10/29/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <QObject>

#include "capture.h"
#include "videoserver.h"
#include "capturethread.h"

class Framework : public QObject
{
    Q_OBJECT
public:
    explicit Framework(QObject *parent = 0);

    Capture *m_capture;
    VideoServer *m_sender;
    //CaptureThread *m_captureThread;

signals:

public slots:

};

#endif // FRAMEWORK_H
