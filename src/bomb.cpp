#include "bomb.h"
#include "player.h"
#include "rlutil.h"
#include <cstdlib>
#include "road.h"
using namespace std;
using namespace rlutil;
bomb::bomb(road *m)
{
    /*road r;
    r.Map();
    r.sendchk(chk2);
    d=0;*/
    //ctor
}

void bomb::show()
{
    setBackgroundColor(10);setColor(10);
    cout<<"ii";
}

void bomb::Clear()
{
    setBackgroundColor(0);setColor(0);
    cout<<"ii";
}

int bomb::run()
{     
    bomb_cnt++;
    if(bomb_cnt%speed) return x*100+y;

    if(d==14)
    { locate(x+2,y-1);Clear();y--;locate(x+2,y-1);show();}
    if(d==15)
    {locate(x+2,y+3);Clear();locate(x+2,y+4); show();y++;}
    if(d==16)
    {locate(x-4,y+1);show(); Clear();x-=2;}
    if(d==17)
    {locate(x+6,y+1);Clear();x+=2; show();}

    setBackgroundColor(0);setColor(15);

    return x*100+y;
}

bomb::~bomb()
{
    //dtor
}

