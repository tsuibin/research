#include"server.h"
#include<unistd.h>

#define bag 1280

Wserver::Wserver()
{
        int sock;
        struct sockaddr_in IP_SET;

        picno=0;
        recivedata = (unsigned char *)malloc(4*3+2+1);
        picdata = (unsigned char *)malloc(640*480*3);//color
        memset(recivedata,0,4*3+2+1);
        memset(picdata,0,640*480*3);

        system("ifconfig");
        puts("Start Net Server!");
	if(-1 == (sock = socket(AF_INET,SOCK_STREAM,0)))
	{
		perror("Socket Error!\n");
		exit(-1);
	}
	puts("Socket Finish!");
	bzero(&IP_SET,sizeof(IP_SET));

	IP_SET.sin_family = AF_INET;
	IP_SET.sin_addr.s_addr = INADDR_ANY;
	IP_SET.sin_port = htons(PORT);
	if(-1 == bind(sock,(struct sockaddr *)&IP_SET,sizeof(IP_SET)))
	{
		perror("Bind Error!\n");
		exit(-1);
	}
	puts("Bind Finish!");
	if(-1 == listen(sock,10))
	{
		perror("Listen Error!\n");
		exit(-1);
	}
	puts("Listen Finish!");
	if(-1 == (fb = accept(sock,NULL,0)))
	{
		perror("Accept Error!\n");
		exit(-1);
	}
	puts("Accept Finish!");
}

Wserver::~Wserver()
{
        free(recivedata);
        free(picdata);
        close(sock);
}

void Wserver::recive()
{
    switch(features)
    {
    case 1:
        recive_color();
        break;
    case 2:
        recive_single();
        break;
    case 3:
        recive_fast();
        break;
    default:
        perror("Invalid Mode!\n");
        exit(-1);
    }
}

void Wserver::recive_picinf()
{
    char picinf[8],temp[4],*p;

    p=picinf+3;

    memset(temp,'\0',sizeof(temp));
    memset(picinf,'\0',sizeof(picinf));

    recv(fb,picinf,sizeof(picinf),0);

    write(fb,picinf,sizeof(picinf));

    strncpy(temp,picinf,3);
    picw = atoi( temp );


    strncpy(temp,p,3);
    pich = atoi( temp );

    features = picinf[6] - 48;

    printf("picw*pich=%d*%d,mode=%d\n",picw,pich,features);
}

void Wserver::recive_color()
{
    for(int i=0;i<picw*pich*3/bag;i++)
    {
        recv(fb,picdata+i*bag,bag,0);
        write(fb,"1",1);
    }
}

void Wserver::recive_single()
{
    for(int i=0;i<picw*pich/bag;i++)
    {
        recv(fb,picdata+i*bag,bag,0);
        write(fb,"1",1);
    }
}

void Wserver::recive_fast()
{
    int i = 5;
    recv(fb, recivedata, 4*3+2, 0);
    //write(fb,"1",1);
    strcpy((char *)picdata, (char *)(recivedata+2));
    //usleep(0);
    //while(i--);
    picno = (*(recivedata+0) * 256) | *(recivedata+1);
}
