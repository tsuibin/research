/**************************************************************************
**   
**   Special keywords: tsuibin 10/28/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#include "capture.h"



Capture::Capture(QObject *parent):QObject(parent)
  //  ui(new Ui::Capture)
{


    image = 0;
    hsv = 0;
    hue = 0;
    mask = 0;
    backproject = 0;
    histimg = 0;
    hist = 0;
    hdims = 16;

    hranges_arr[0] = 0;
    hranges_arr[1] = 180;

    hranges = hranges_arr;

    track_object = 0;

    vmin = 10;
    vmax = 256;
    smin = 30;

    backproject_mode = 0;
    select_object = 0;
    show_hist = 1;

 //   ui->setupUi(this);

    capture = 0;
    run();
}

Capture::~Capture()
{
    //delete ui;
}

void Capture::run()
{
    capture = cvCaptureFromCAM( 0 );
    //capture = cvCaptureFromAVI("/home/tsuibin/1.avi");
    qDebug() << "here";

    qDebug() << "thread run";
    if( !capture )
    {
        qDebug() << "Could not initialize capturing...\n";
        return;
    }else{
        readVideoData();
    }

}
void Capture::readVideoData()
{
    qDebug()<<"readVideoData";

    while(1){
          IplImage* frame = 0;
          int c;

          frame = cvQueryFrame( capture );
//          if( !frame )
//              break;

          if( !image )
          {
               /*allocate all the buffers*/
              image = cvCreateImage( cvGetSize(frame), 8, 3 );
              image->origin = frame->origin;
              hsv = cvCreateImage( cvGetSize(frame), 8, 3 );
              hue = cvCreateImage( cvGetSize(frame), 8, 1 );
              mask = cvCreateImage( cvGetSize(frame), 8, 1 );
              backproject = cvCreateImage( cvGetSize(frame), 8, 1 );
              hist = cvCreateHist( 1, &hdims, CV_HIST_ARRAY, &hranges, 1 );
              histimg = cvCreateImage( cvSize(320,200), 8, 3 );
              // histimg = cvCreateImage( cvSize(100,100), 8, 3 );
              cvZero( histimg );
          }


          cvCopy( frame, image, 0 );
          cvCvtColor( image, hsv, CV_BGR2HSV );

//          if( track_object )
//          {
//              int _vmin = vmin, _vmax = vmax;

//              cvInRangeS( hsv, cvScalar(0,smin,MIN(_vmin,_vmax),0),
//                          cvScalar(180,256,MAX(_vmin,_vmax),0), mask );
//              cvSplit( hsv, hue, 0, 0, 0 );
//              cvCalcBackProject( &hue, backproject, hist );
//              cvAnd( backproject, mask, backproject, 0 );
//              cvCamShift( backproject, track_window,
//                          cvTermCriteria( CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10, 1 ),
//                          &track_comp, &track_box );
//              track_window = track_comp.rect;

//              if( backproject_mode )
//                  cvCvtColor( backproject, image, CV_GRAY2BGR );
//              if( !image->origin )
//                  track_box.angle = -track_box.angle;
//              cvEllipseBox( image, track_box, CV_RGB(255,0,0), 3, CV_AA, 0 );
//          }

          if( select_object && selection.width > 0 && selection.height > 0 )
          {
              cvSetImageROI( image, selection );
              cvXorS( image, cvScalarAll(255), image, 0 );
              cvResetImageROI( image );
          }


          //send data

           // emit sendVideoData(*image);

          //recevice data

         // cvShowImage( "Video_2010", 0 );


          //LOCAL
          cvShowImage( "Video_2010", image );



          c = cvWaitKey(10);
          /*
          "\tESC - quit the program\n"
          "\tc - stop the tracking\n"
          "\tb - switch to/from backprojection view\n"
          "\th - show/hide object histogram\n"
          "To initialize tracking, select the object with mouse\n" );
          */
          if( (char) c == 27 )
              break;
    }//while

      cvReleaseCapture( &capture );
      cvDestroyWindow("Video_2010");
}


void Capture::showImage(IplImage image)
{
    //qDebug() << image.trimmed();
    cvShowImage( "Video_2010", &image );//(IplImage *)
}

CvScalar Capture::hsv2rgb( float hue )
{
    int rgb[3], p, sector;
    static const int sector_data[][3]=
        {{0,2,1}, {1,2,0}, {1,0,2}, {2,0,1}, {2,1,0}, {0,1,2}};
    hue *= 0.033333333333333333333333333333333f;
    sector = cvFloor(hue);
    p = cvRound(255*(hue - sector));
    p ^= sector & 1 ? 255 : 0;

    rgb[sector_data[sector][0]] = 255;
    rgb[sector_data[sector][1]] = 0;
    rgb[sector_data[sector][2]] = p;

    return cvScalar(rgb[2], rgb[1], rgb[0],0);
}
