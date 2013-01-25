#ifndef server_h
#define server_h
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<stdio.h>
#include<strings.h>
#include<unistd.h>
#include<string.h>

#define PORT 8000

class Wserver
{
	public:
                Wserver();
                ~Wserver();

                int picw,pich;
                unsigned char *picdata;
                int features;
                short picno;

		void recive();
                void recive_picinf();
	private:
                int fb;
                int sock;
                unsigned char *recivedata;
                void recive_color();
                void recive_single();
                void recive_fast();
};
#endif
