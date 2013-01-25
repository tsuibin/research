#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/mman.h>
#include <string.h>
#include <error.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <jpeglib.h>
#include <jerror.h>
#include <time.h>
#include <opencv/highgui.h>


#define FB_DEV "/dev/fb0"

int frameBufferWidth;
int frameBufferHeight;
int frameBufferBpp;
int *frameBufferMem;


int fb_init(void)
{
	int fb;
	struct fb_var_screeninfo fb_inf;

	if((fb = open(FB_DEV, O_RDWR)) < 0) {
		perror("open fb0");
		exit(1);
	}

	ioctl(fb, FBIOGET_VSCREENINFO, &fb_inf);

	frameBufferWidth = fb_inf.xres;
	frameBufferHeight = fb_inf.yres;
	frameBufferBpp = fb_inf.bits_per_pixel;
	printf("fb_info-->w: %d;h: %d;bpp: %d\n",  frameBufferWidth,  frameBufferHeight,  frameBufferBpp);

	frameBufferMem = (int *)mmap(0, ( frameBufferWidth *  frameBufferHeight *  frameBufferBpp) / 8, PROT_READ | PROT_WRITE, MAP_SHARED, fb, 0);

	if( frameBufferMem == MAP_FAILED ) {
		perror("mmap");
		exit(1);
	}

	return 0;
}

int fb_pixel(const unsigned char *q,int pic_w,int pic_h)
{
	int i, j;
	const unsigned int *ptr = (const unsigned int *)q;

	for(i = 0; i < pic_w; i++) {
		for(j = 0; j < pic_h; j++) {
			*(frameBufferMem + j * frameBufferWidth + i ) = *(ptr + j * pic_w + i);
		}
	}

	return 0;
}

int main(int argc, char* argv[])
{
	unsigned int i;
	int size = 640 * 480;
	const unsigned char* src;
	unsigned char * des = (unsigned char *)malloc( size * sizeof(int) );
	unsigned int * ptr;
	CvCapture* capture = cvCreateCameraCapture( -1 );
	IplImage * frame;

	fb_init();
	char cr,cg,cb;
	int color;
	while( 1 ) {

		frame = cvQueryFrame( capture );

		if ( !frame ) break;

		src = (unsigned char *)frame->imageData;
		ptr = (unsigned int *)des;

		for ( i = 0; i < size; i++)
		{
			
			/*
			*ptr++ = *src++;//b
			*ptr++ = *src++;//g
			*ptr++ = *src++;//r
			*ptr++ = 0;
			*/
			
			/*
			cb = *src++;//b
			cg = *src++;//g
			cr = *src++;//r
			*ptr = cb;
			ptr++;
			*ptr = cg;
			ptr++;
			*ptr = cr;
			ptr++;
			*ptr = 0;
			ptr++;
			*/
			
			cb = *src++;
			cg = *src++;
			cr = *src++;
			color = ( cr << 16 & 0xff0000) | (cg << 8 & 0xff00) | (cb & 0xff);
			*ptr++ = color;
			
		}

		fb_pixel( des, frame->width, frame->height );
		usleep( 150000 );
	}

	cvReleaseCapture( &capture );

	return 0;
}


