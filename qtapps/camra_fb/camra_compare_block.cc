#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <linux/fb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <opencv/highgui.h>

int fc;

int frameBufferWidth;
int frameBufferHeight;
int frameBufferBpp;
int *fbmem;


int fb_init(void)
{
	int fb;
	struct fb_var_screeninfo fb_inf;

	if((fb = open("/dev/fb0", O_RDWR)) < 0) {
		perror("open fb0");
		exit(1);
	}

	ioctl(fb, FBIOGET_VSCREENINFO, &fb_inf);

	frameBufferWidth = fb_inf.xres;
	frameBufferHeight = fb_inf.yres;
	frameBufferBpp = fb_inf.bits_per_pixel;
	printf("fb_info-->w: %d;h: %d;bpp: %d\n",  frameBufferWidth,  frameBufferHeight,  frameBufferBpp);

	fbmem = (int *)mmap(0, ( frameBufferWidth *  frameBufferHeight *  frameBufferBpp) / 8, PROT_READ | PROT_WRITE, MAP_SHARED, fb, 0);

	if( fbmem == MAP_FAILED ) {
		perror("mmap");
		exit(1);
	}

	return 0;
}


void fb_pixel(const unsigned char *ptr,int blockNO, int blockSize)
{
	//方块
	   int i,j;
	 for(i = 0; i < 640; i++) {
	 	for(j =0; j < 480; j++){
	 		*(fbmem + j*frameBufferWidth+i ) = *(ptr + j*640 +i) << 8;
		}
	 }
	 

	 return;
}


void compare80x60RGB(unsigned char * newFrame,
		unsigned char * oldFrame,
		int byteCount)
{
	/*
	   byteCount 的值一般为 640*480*3
	   (RGB数据)
	   块数据大小 80x60x3
	 */
	fc++;
	char blockNO = 0;
	const int blockSize = 80 * 60;
	int i,j,x;
	int diffCount;
	int abs;

	for(i = 0; i < byteCount; i++){
		//printf(" bloc : %d \n", i );//4860	
		//printf(" 4801 : %d \n", i%blockSize );//60
		if ( i%blockSize == 0)
		{
			blockNO++; //块号
			//printf("块号 %d\n",blockNO); 
		}

		if ( *(newFrame + i) != *(oldFrame + i) ){

			abs = *(newFrame +i) - *(oldFrame + i);
			if ( abs < 0 ) {
				abs = -abs;
			}
			//printf("!abs %d \n",abs ); 

			if(abs > 70 ) {

				//发送块号
				//printf("第%d帧 第%d 块数据有更新\n",fc,blockNO);
				//printf("!abs %d  %d\n",abs, i ); 
				//send blockNO

				//发送之后 80*60*3 字节数据
				unsigned char *ptr = ( newFrame + blockNO * blockSize );
				//fb_pixel(ptr, blockNO, blockSize);
				//for(j = 0; j < blockSize ; j++){
					//send *(ptr +j);
				//}

				i = ( blockNO * blockSize -1 );
			}
		}
	}
	//printf("=== frame ===\n"); 
}

int main(int argc, char* argv[])
{
	unsigned int i;
	unsigned char* src;
	unsigned char * newImg = (unsigned char *)malloc( 640*480 );
	unsigned char * oldImg = (unsigned char *)malloc( 640*480 );
	unsigned char * ptr;
	
	fb_init();

	CvCapture* capture = cvCreateCameraCapture( -1 );
	IplImage * frame;
	int cc = 3;

	while( cc ) {

		frame = cvQueryFrame( capture );

		if ( !frame ) break;

		src = (unsigned char *)frame->imageData;



		ptr = newImg;

		for ( i = 0; i < 640*480; ++i)
		{
			src++;
			*ptr++ = *src++;
			src++;
			//*ptr++ = *src++;
			//*ptr++ = *src++;
		}


		compare80x60RGB(newImg,oldImg,640*480);

		ptr = oldImg;

		src = (unsigned char *)frame->imageData;
		for (i = 0; i < 640*480; ++i)
		{
			src++;
			*ptr++ = *src++;
			src++;			

		}

		//				usleep( 5000000 );
	}


	cvReleaseCapture( &capture );

	return 0;
}


