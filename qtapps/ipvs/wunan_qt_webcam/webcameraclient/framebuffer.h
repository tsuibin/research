#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H
#include<sys/ioctl.h>
#include<sys/mman.h>
#include<linux/fb.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
class Wframebuffer
{
	public:
                Wframebuffer();
                ~Wframebuffer();
		int *fbmem;
                short fw,fh,fbits;
	private:
		int fb;
		struct fb_var_screeninfo fb_var;
};

#endif // FRAMEBUFFER_H
