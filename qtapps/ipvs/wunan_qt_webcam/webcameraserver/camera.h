#ifndef camera_h
#define camera_h
#include <opencv/highgui.h>
#include <stdio.h>
class Wcamera
{
	public:
		Wcamera();
		~Wcamera();
                char *init();
                IplImage *temp;
	private:

                CvCapture* video_dev;
};
#endif
