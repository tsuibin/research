#ifndef play_h
#define play_h
#include<stdio.h>
#include<stdlib.h>

class Wplay
{
	public:
                void playpic();
                unsigned char *picdata;
		int *fbmem;
		int picw,pich;
                short fw,fh;
                int features;
                short picno;
private:
                void play_color();
                void play_single();
                void play_fast();
};
#endif
