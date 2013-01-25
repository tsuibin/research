#include"play.h"
#include<unistd.h>
void Wplay::playpic()
{
     switch(features)
     {
     case 1:
         play_color();
         break;
     case 2:
         play_single();
         break;
     case 3:
         play_fast();
         break;
     default:
         perror("Features select Error!\n");
         exit(1);
     }
}

void Wplay::play_color()
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

void Wplay::play_single()
{
    int g;
    for(int i = 0; i < picw*pich; i++)
    {
        g = *picdata++;
        *(fbmem+i/picw*fw+i%picw) = (g<<8) & 0xff00;
    }
}

void Wplay::play_fast()
{
    int g;
    int temp = picno/(640/4)*3*fw+picno%(640/4)*4;
    //for(int picno=0;picno<640*480/(4*3);picno++){//test for fast
    for(int i=0;i<4*3;i++)
    {
        g = *picdata++;
        *(fbmem+temp+i/4*fw+i%4) = (g<<8) & 0xff00;
    }
    //printf("picno=%d\n",picno);
    //usleep(400);}
}
