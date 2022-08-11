#include "road.h"
#include "rlutil.h"
#include <cstdlib>

using namespace std;
using namespace rlutil;
road::road(int x,int y){

   //m_x=x;
   //m_y=y;
   Map();
   fk();
    //ctor
}
void  road::sendchk(int b[][41] )
{
    int i,j;
    for(i=0;i<80;i++){
     for(j=0;j<41;j++){
       b[i][j]=chk[i][j];

     }
    }
}
void road::Map(void)
{
    int i,j;
    for(i=0;i<80;i++)
    {
        for(j=0;j<41;j++)
        {
            chk[i][j]=0;
        }
    }
    Big(5,8);Big(5,20);Min(5,32);Min(5,44);Big(5,56);Big(5,68);
    Min(29,8);Min(29,20);Min(29,56);Min(29,68);
    Small(23,2);Small(23,14);Small(23,20);Min(23,32);Min(23,44);Small(23,56);Small(23,62);Small(23,74);
    Small(26,38);Small(17,32);Small(17,44);
    Small(35,32);Small(35,38);Small(35,44);Small(38,32);Small(38,44);

    Background(41,80);
}

void road::Big(int x,int y){
int j,i;
locate(y,x);
setBackgroundColor(7);setColor(7);
for(i=0;i<6;i+=2){
    locate(y+i,x);
    chk[y+i-1][x-1]=1;
    chk[y+i][x-1]=1;
        cout<<"口";
        for(j=0;j<15;j++){locate(y+i,x+j);cout<<"口"; chk[y+i-1][x+j-1]=1;chk[y+i][x+j-1]=1;  }
}
}
void road::Min(int x,int y){
int j,i;
locate(y,x);
 setBackgroundColor(7);setColor(7);
for(i=0;i<6;i+=2){
    locate(y+i,x);
    chk[y+i-1][x-1]=1;
    chk[y+i][x-1]=1;
        cout<<"口";
        for(j=0;j<9;j++){locate(y+i,x+j);cout<<"口"; chk[y+i-1][x+j-1]=1;chk[y+i][x+j-1]=1; }
}
}
void road::Small(int x,int y){
int j,i;
locate(y,x);
 setBackgroundColor(7);setColor(7);
for(i=0;i<6;i+=2){
    locate(y+i,x);
     chk[y+i-1][x-1]=1;
    chk[y+i][x-1]=1;
        cout<<"口";
        for(j=0;j<3;j++){locate(y+i,x+j);cout<<"口";chk[y+i-1][x+j-1]=1;chk[y+i][x+j-1]=1;   }
}
}

void road::Background(int h,int w)
  {
    //setBackgroundColor(3);
    locate(1, 1);
    for (int i=0; i<w; i++){cout << "=";  chk[i][0]=2;  }
    locate(1, h);
    for (int i=0; i<w; i++) {cout << "=";  chk[i][h-1]=2;  }

    for (int i=0; i<h; i++) {
        locate(1, 1+i);
        chk[0][i]=2;
        cout << "|";
        locate(w, 1+i);
        chk[w-1][i]=2;
        cout << "|";
    }

}
int road::fk()
{int fff=0;
    for(int j=0; j<41; j++)
    {
        for(int i=0; i<80; i++)
        {
            all_m[fff]=chk[i][j];
            fff++;
        }
    }
}
road::~road()
{
    //dtor
}
