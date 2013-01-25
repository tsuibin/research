#include"play.h"
void Wplay::playpic()
{
        unsigned int r,g,b;
        for(int i = 0; i < picw*pich; i++)
        {
                b=*picdata++;
                g=*picdata++;
                r=*picdata++;
                *(fbmem+i/picw*fw+i%picw) = ((r<<16)&0xff0000)|((g<<8)&0xff00)|(b&0xff);
	}
}
