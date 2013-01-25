#include "server.h"
#define bag 1280 //send colordata or gdata bag size
Wserver::Wserver()//init net server
{
	char IP[15];
	int PORT;
	struct sockaddr_in IP_SET;
	olddata = (char *)malloc(640*480);
	memset(olddata,0,640*480);
	puts("Input Server IP:");
	scanf("%s",IP);
	getchar();
	puts("Input Server Port:");
	scanf("%d",&PORT);
	getchar();
	puts("Select features(1:color;2:single;3:fast.):");
	scanf("%d",&features);
	getchar();
        if(3 == features)
        {
                puts("Input colorpoor[0~3072):");
                scanf("%d",&COLORPOOR);
                getchar();
        }
	if(-1 == (sock = socket(AF_INET,SOCK_STREAM,0)))
	{
		perror("Socket Error!\n");
		exit(-1);
	}
	puts("Socket Finish!");
	IP_SET.sin_family=AF_INET;
	inet_pton(AF_INET,IP,&IP_SET.sin_addr);
	IP_SET.sin_port=htons(PORT);
	if(-1 == connect(sock,(struct sockaddr*)&IP_SET,sizeof(IP_SET)))
	{
		perror("Connect Error!\n");
		exit(-1);
	}
	puts("Connect Finish!");
}

Wserver::~Wserver()//close net sever
{
        free(olddata);
        close(sock);
}

void Wserver::itoa(int j,char *p)
{
	for( p += lenth(j); j >= 1; p--, j /= 10 )
		*p = j % 10 + 48;
}
int Wserver::lenth(int i)
{
	int j = 0;
	for( ; i >= 1; i /= 10 )
		j++;
	return j-1;
}

void Wserver::send_picinf()
{
	char picinf[8];
	char temp[8];

	memset(picinf,'\0',sizeof(picinf));
	memset(temp,'\0',sizeof(temp));

	itoa(picw,picinf);

	itoa(pich,temp);
	strcat(picinf,temp);

	picinf[strlen(picinf)] = features +48;

	write(sock,picinf,sizeof(picinf));

	memset(temp,'\0',sizeof(temp));
	recv(sock,temp,sizeof(temp),0);

	puts(picinf);
}

void Wserver::send_picdata()
{
	switch(features)
	{
		case 1://color
			send_color();
			break;
		case 2://single
			send_single();
			break;
		case 3://fast
			send_fast();
			break;
		default:
			perror("Features select Error!\n");
			exit(-1);
	}
}

void Wserver::send_color()
{
	char temp;
	for(int i=0;i<pich*picw*3/bag;i++)
	{
		write(sock,picdata+i*bag,bag);
                recv(sock,&temp,1,0);
	}
}

void Wserver::send_single()
{
	char temp;

	char *data =(char *) malloc(pich*picw);

	for(int i=0;i<pich*picw*3;i++)//数据转换
		*(data+(i+2)/3) = *(picdata+i);//space in Wserver::Wserver()

	for(int i=0; i<pich*picw/bag; i++)
	{
		write(sock,data+i*bag,bag);
                recv(sock,&temp,1,0);
	}
	free(data);
}

/*char picnoanddata,no data[1:0],data data[pich*picw+2:2]*/
void Wserver::send_fast()
{
	//do to get newdata;
	char *newdata =(char *) malloc(pich*picw);
		if(newdata == NULL)
		{
			printf("malloc error!\n"); 
		}

	for(int i=0;i<pich*picw*3;i++)//数据转换
		*(newdata+(i+2)/3) = *(picdata+i);//space in Wserver::Wserver()

	//comper with old data,add the count;
        unsigned char *senddata = (unsigned char *)malloc(4*3+2+1);
	for(int i=0;i<640*480/12;i++)
	{
		memset(senddata,'\0',4*3+2+1);
                int newdatatotal=0,olddatatotal=0;

                senddata[1]=i%256;//L_picno
                senddata[0]=i/256;//H_picno

		for(int j=0;j<4*3;j++)
		{
                        int temp=i/(picw/4)*640*3+i%(640/4)*4+j/4*640+j%4;
                        newdatatotal+=*(newdata+temp);
                        olddatatotal+=*(olddata+temp);//space in Wserver::Wserver()
                        *(senddata+2+j) = *(olddata+temp) = *(newdata+temp);
		}
                if(COLORPOOR <= abs(newdatatotal-olddatatotal))//pass half send data;
                        //{
                        write(sock,senddata,4*3+2);
                        //recv(sock,senddata,1,0);}

	}
	free(senddata);
	free(newdata);
}
