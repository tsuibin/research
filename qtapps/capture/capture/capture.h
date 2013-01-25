/**************************************************************************
**   
**   Special keywords: tsuibin 10/28/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#ifndef CAPTURE_H
#define CAPTURE_H

#include <QObject>
#include <QThread>
#include <QDebug>

#define CV_NO_BACKWARD_COMPATIBILITY

#include "cv.h"
#include "highgui.h"

namespace Ui {
    class Capture;
}

class Capture : public QObject
{
    Q_OBJECT

public:
    Capture(QObject *parent = 0);
    ~Capture();

    void run();

    IplImage *image;
    IplImage *hsv;
    IplImage *hue;
    IplImage *mask;
    IplImage *backproject;
    IplImage *histimg;
    CvHistogram *hist;
    int hdims;

    float hranges_arr[2];
    float* hranges;

    int track_object;
    CvRect track_window;
    CvRect selection;

    int vmin;
    int vmax;
    int smin;

    CvConnectedComp track_comp;
    CvBox2D track_box;
    int backproject_mode;
    int select_object;
    int show_hist;

    CvScalar hsv2rgb( float hue );
    void readVideoData();

    CvCapture* capture;

public slots:
    void showImage(IplImage);

signals:
    void sendVideoData(IplImage);

private:
    Ui::Capture *ui;

protected:

};

#endif // CAPTURE_H
