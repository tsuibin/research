#ifndef play_h
#define play_h
#include<unistd.h>

class Wplay
{
	public:
                void playpic();
                char *picdata;
		int *fbmem;
		int picw,pich;
                short fw,fh;
};
#endif
