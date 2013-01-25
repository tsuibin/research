#ifndef server_h
#define server_h
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

class Wserver
{
	public:
		Wserver();
		~Wserver();

		short picw,pich;
                char *picdata;

                void send_picinf();
                void send_picdata();
	private:
		int sock;
                int features;
                char *olddata;
                int COLORPOOR;

		void itoa(int n,char *temp);
                int lenth(int i);

                void send_color();
                void send_single();
                void send_fast();

};
#endif
