#include "player.h"
#include "rlutil.h"
#include <cstdlib>
#include "road.h"
using namespace std;
using namespace rlutil;
player::player(road *m,int x,int y)
{
    pm=m;
    mp_x=x;
    mp_y=y;
    //update_map_status();
   /*locate(1,1);
    setBackgroundColor(0);

    locate(1,1);
    setBackgroundColor(0);
    for(int j=0; j<41; j++)
    {
        for(int i=0; i<80; i++)
        {
            cout<<chk2[i][j];

        }
    }*/
    show(KEY_UP);
}

void player::show(int i)
{
    if(i==KEY_UP)
    {
        setBackgroundColor(0);setColor(0);locate(mp_x,mp_y);
        cout <<"口";
        setBackgroundColor(15);setColor(15);
        cout <<"口";
        setBackgroundColor(0);setColor(0);
        cout <<"口";
        setBackgroundColor(0);setColor(15);locate(mp_x,mp_y+1);
        cout <<"回";
        setBackgroundColor(15);setColor(15);
        cout <<"口";
        setBackgroundColor(0);setColor(15);
        cout <<"回";
        setBackgroundColor(0);setColor(15);locate(mp_x,mp_y+2);
        cout <<"回";
        setBackgroundColor(15);setColor(15);
        cout <<"口";
        setBackgroundColor(0);setColor(15);
        cout <<"回";
    }
    else if(i==KEY_RIGHT)
    {
        setBackgroundColor(0);setColor(15);locate(mp_x,mp_y);
        cout <<"回回";
        setBackgroundColor(15);locate(mp_x,mp_y+1);
        cout <<"口口口";
        setBackgroundColor(0);setColor(15);locate(mp_x,mp_y+2);
        cout <<"回回";
    }
    else if(i==KEY_DOWN)
    {
        setBackgroundColor(0);setColor(0);locate(mp_x,mp_y+2);
        cout <<"口";
        setBackgroundColor(15);setColor(15);
        cout <<"口";
        setBackgroundColor(0);setColor(0);
        cout <<"口";
        setBackgroundColor(0);setColor(15);locate(mp_x,mp_y+1);
        cout <<"回";
        setBackgroundColor(15);setColor(15);
        cout <<"口";
        setBackgroundColor(0);setColor(15);
        cout <<"回";
        setBackgroundColor(0);setColor(15);locate(mp_x,mp_y);
        cout <<"回";
        setBackgroundColor(15);setColor(15);
        cout <<"口";
        setBackgroundColor(0);setColor(15);
        cout <<"回";
    }
    else if(i==KEY_LEFT)
    {
        setBackgroundColor(0);setColor(15);locate(mp_x+2,mp_y);
        cout <<"回回";
        setBackgroundColor(15);locate(mp_x,mp_y+1);
        cout <<"口口口";
        setBackgroundColor(0);setColor(15);locate(mp_x+2,mp_y+2);
        cout <<"回回";
    }
}

int player::Move(int key)
{   
    int t=0;
    direction=key;
    if(direction==KEY_UP||direction==KEY_RIGHT||direction==KEY_DOWN||direction==KEY_LEFT) 
    {
        Clear();t=1;
        fg=direction;
        if(i==direction&&t)
        {
            if(direction==KEY_UP){mp_y-=1;t--;locate(mp_x,mp_y);if(chk2[mp_x][mp_y-1]>0||chk2[mp_x+1][mp_y-1]>0||chk2[mp_x+2][mp_y-1]>0||chk2[mp_x+3][mp_y-1]>0)mp_y+=1;show(direction);locate(mp_x,mp_y);}
            else if(direction==KEY_RIGHT){mp_x+=2;t--;locate(mp_x,mp_y);if(chk2[mp_x+3][mp_y]>0||chk2[mp_x+3][mp_y+1]>0||chk2[mp_x+3][mp_y-1]>0)mp_x-=2;show(direction);locate(mp_x,mp_y);}
            else if(direction==KEY_DOWN){mp_y+=1;t--;locate(mp_x,mp_y);if(chk2[mp_x][mp_y+1]>0||chk2[mp_x+1][mp_y+1]>0||chk2[mp_x+2][mp_y+1]>0||chk2[mp_x+3][mp_y+1]>0)mp_y-=1;show(direction);locate(mp_x,mp_y);}
            else if(direction==KEY_LEFT){mp_x-=2;t--;locate(mp_x,mp_y);if(chk2[mp_x-1][mp_y]>0||chk2[mp_x-1][mp_y+1]>0||chk2[mp_x-1][mp_y-1]>0||(mp_x==0&&mp_y==38)||mp_x==0)mp_x+=2;show(direction);locate(mp_x,mp_y);}
        }
        else if(t)
        {
            show(direction);t=0;locate(mp_x,mp_y);
        }
        i=direction;
    }
    return mp_x*100+mp_y;
}

void player::sendec(int a[])
{
    a[0]=fg;
    a[1]=mp_x;
    a[2]=mp_y;
}

void player::Clear(void)
{
    setBackgroundColor(0);setColor(0);
    locate(mp_x,mp_y);
    cout <<"口口口";
    locate(mp_x,mp_y+1);
    cout <<"回回回";
    locate(mp_x,mp_y+2);
    cout <<"口口口";
}

int player::update_map_status()
{
    int cnt=0;
    for(int j=0; j<41; j++)
    {
        for(int i=0; i<80; i++)
        {
            chk2[i][j]= all_m2[cnt];
            cnt++;
        }
    }
}

player::~player()
{
    //dtor
}
