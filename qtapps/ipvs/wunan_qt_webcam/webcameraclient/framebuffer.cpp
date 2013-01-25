#include "framebuffer.h"

Wframebuffer::Wframebuffer()
{
    if(-1 == (fb = open("/dev/fb0", O_RDWR)))
    {
        perror("Open /dev/fb0 error!");
        exit(-1);
    }
    else puts("Open /dev/fb0 OK!");
    ioctl(fb, FBIOGET_VSCREENINFO, &fb_var);
    fw = fb_var.xres;
    fh = fb_var.yres;
    fbits = fb_var.bits_per_pixel;
    printf("Freamebuffer:%d*%d-%d\n", fw, fh, fbits);
    fbmem =(int *)mmap(0, fw*fh*fbits/8, PROT_READ|PROT_WRITE, MAP_SHARED, fb, 0);
    close(fb);
}
Wframebuffer::~Wframebuffer()
{
    printf("Close /dev/fb0!");
    close(fb);
}
