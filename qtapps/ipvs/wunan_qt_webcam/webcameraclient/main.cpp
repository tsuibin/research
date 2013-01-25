#include"camera.h"//the header for camera
#include"play.h"//the header for local play
#include"framebuffer.h"//the header for local screen
#include"server.h"
int main()
{
    Wframebuffer framebuffer;//get framebuffer "*fbmem",with frembuffer init
    Wcamera camera;//open camera ,with camera init
    Wplay play;//get ready for play
    Wserver server;

    //pass the framebuffer inf to play
    {
        play.fbmem = framebuffer.fbmem;//pass the fbmem
        play.fw = framebuffer.fw;//pass the fw
        play.fh = framebuffer.fh;//pass the fh
    }

    //get inf from camera for play and send
    {
        server.picdata = play.picdata = camera.init();//get picdata from picinf
        server.picw = play.picw = camera.temp->width;//get picw from picinf
        server.pich = play.pich = camera.temp->height;//get pich from picinf
        server.send_picinf();//send picinf
    }
    puts("send over!\n");

    //system("clear");

    while(1)//send pic and play pic
    {
        //play.playpic();//play pic
        server.send_picdata();//send picdata
	play.picdata = camera.init();//get picdata from picinf again
    }

    return 0;
}
