#include"camera.h"
Wcamera::Wcamera()
{
    video_dev = cvCreateCameraCapture( -1 );
    /*if(-1 == (video_dev = cvCreateCameraCapture( -1 )))
    {
        perror("Open camera Error!\n");
    }
    else puts("Open camera OK!");//open camera*/
}
char *Wcamera::init()
{
	temp = cvQueryFrame( video_dev );
        return temp->imageData;
}
Wcamera::~Wcamera()
{
        cvReleaseCapture( &video_dev );//close camera
}
