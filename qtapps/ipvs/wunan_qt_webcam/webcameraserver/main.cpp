#include"play.h"//the header for local play
#include"framebuffer.h"//the header for local screen
#include"server.h"
int main()
{
    Wframebuffer framebuffer;//get framebuffer "*fbmem",with frembuffer init
    Wplay play;//get ready for play
    Wserver server;

    //pass the framebuffer inf to play
    play.fbmem = framebuffer.fbmem;//pass the fbmem
    play.fw = framebuffer.fw;//pass the fw
    play.fh = framebuffer.fh;//pass the fh

    server.recive_picinf();//recive the picinf

    //pass pic picinf and mode
    play.picw = server.picw;
    play.pich = server.pich;
    play.features = server.features;
    printf("features=%d\n",play.features);

//    system("clear");

    for(;;)//get pic and play pic
    {
        server.recive();//recive the picdata
        play.picdata = server.picdata;//pass picdata from server to play
        play.picno = server.picno;//get the picno
        play.playpic();//play pic
    }

    return 0;
}
