#include <iostream>
#include <vector>
#include "rlutil.h"
#include "player.h"
#include "road.h"
#include "bomb.h"
using namespace std;
using namespace rlutil;

/* Default values for game's parameter */
#define map_width 80
#define map_height 41
#define player1_posx_init 2
#define player1_posy_init 2
#define player2_posx_init 74
#define player2_posy_init 2

int main()
{

    int keyboard,player1_bomb_cnt=0,player2_bomb_cnt=0,get_position=0,bombpos2=0,status=1;
    int player1_lastkey,player2_lastkey;
    int map_status[map_width][map_height]={0};
    int cnt=0;
    vector<bomb*> bombs;
    vector<bomb*> bombs2;


    //initialize the map and tanks
    road GameMap(map_width,map_height);
    player player1_tank(&GameMap,player1_posx_init,player1_posy_init);
    player player2_tank(&GameMap,player2_posx_init,player2_posy_init);



    //read the map status
    for(int j=0; j<map_height; j++)
    {
        for(int i=0; i<map_width; i++)
        {
            map_status[i][j]= *(GameMap.Getch()+cnt);
            cnt++;
        }
    }

    while(status)
    {
        if (kbhit())
        {
            keyboard=getkey();
            //read player1 keyboard
            if(keyboard==KEY_UP||keyboard==KEY_RIGHT||keyboard==KEY_DOWN||keyboard==KEY_LEFT)get_position=player1_tank.Move(keyboard);
            //read player2 keyboard
            if(keyboard==KEY_HOME||keyboard==KEY_PGDOWN||keyboard==KEY_END||keyboard==KEY_DELETE)
            {
                if(keyboard==KEY_HOME)player2_lastkey=KEY_UP;
                if(keyboard==KEY_PGDOWN)player2_lastkey=KEY_RIGHT;
                if(keyboard==KEY_END)player2_lastkey=KEY_DOWN;
                if(keyboard==KEY_DELETE)player2_lastkey=KEY_LEFT;
                bombpos2=player2_tank.Move(player2_lastkey);
            }
            //detect player1's bomb
            if(keyboard==KEY_SPACE)
            {
                bombs.push_back(new bomb(&GameMap));
                bombs[player1_bomb_cnt]->set_direction(player1_lastkey);
                bombs[player1_bomb_cnt]->set_position(get_position/100,get_position%100);
                player1_bomb_cnt++;
            }
            //detect player2's bomb
            if(keyboard==KEY_ENTER)
            {
                bombs2.push_back(new bomb(&GameMap));
                bombs2[player2_bomb_cnt]->set_direction(player2_lastkey);
                bombs2[player2_bomb_cnt]->set_position(bombpos2/100,bombpos2%100);
                player2_bomb_cnt++;
            }
            if (keyboard!=KEY_SPACE) player1_lastkey = keyboard;
        }

        for (vector<bomb*>::iterator it=bombs.begin(); it!=bombs.end(); it++)
        {
            int position,direction,pos_x,pos_y;

            position=(*it)->run();
            direction=(*it)->get_position();

            pos_x=position/100;pos_y=position%100;
            if(map_status[position/100][position%100-3]==2&&direction==14){it=bombs.erase(it);it--;player1_bomb_cnt--;setBackgroundColor(0);setColor(0);locate(pos_x+2,pos_y-1);cout<<"ii";}
            if(map_status[position/100][position%100+3]==2&&direction==15){it=bombs.erase(it);it--;player1_bomb_cnt--;setBackgroundColor(0);setColor(0);locate(pos_x+2,pos_y+3);cout<<"ii";}
            if(map_status[position/100-4][position%100]==2&&direction==16){it=bombs.erase(it);it--;player1_bomb_cnt--;setBackgroundColor(0);setColor(0);locate(pos_x-2,pos_y+1);cout<<"ii";}
            if((position/100==70)&&direction==17){it=bombs.erase(it);it--;player1_bomb_cnt--;setBackgroundColor(0);setColor(0);locate(pos_x+6,pos_y+1);cout<<"ii";}

            if(map_status[pos_x+2][pos_y-2]==1&&direction==14)
            {
                if(map_status[pos_x+2][pos_y-2]!=1)
                {
                    setBackgroundColor(0);setColor(0);locate(pos_x+2,pos_y-1);cout<<"ii";locate(pos_x,pos_y-2);cout<<"口口口";
                    map_status[pos_x-1][pos_y-3]=0;map_status[pos_x+2][pos_y-3]=0;
                    map_status[pos_x][pos_y-3]=0;map_status[pos_x+3][pos_y-3]=0;
                    map_status[pos_x+1][pos_y-3]=0;map_status[pos_x+4][pos_y-3]=0;

                }
                else
                {
                    setBackgroundColor(0);setColor(0);locate(pos_x+2,pos_y-1);cout<<"ii";locate(pos_x,pos_y-1);cout<<"口口口";
                    map_status[pos_x-1][pos_y-2]=0;map_status[pos_x+2][pos_y-2]=0;
                    map_status[pos_x][pos_y-2]=0;map_status[pos_x+3][pos_y-2]=0;
                    map_status[pos_x+1][pos_y-2]=0;map_status[pos_x+4][pos_y-2]=0;
                }
                it=bombs.erase(it);it--;player1_bomb_cnt--;}

                if(map_status[pos_x+2][pos_y+2]==1&&direction==15)
                {
                    if(map_status[pos_x+2][pos_y+2]!=1)
                    {
                        setBackgroundColor(0);setColor(0);locate(pos_x+2,pos_y+3);cout<<"ii";locate(pos_x,pos_y+4);cout<<"口口口";
                        map_status[pos_x-1][pos_y+3]=0;map_status[pos_x+2][pos_y+3]=0;
                        map_status[pos_x][pos_y+3]=0;map_status[pos_x+3][pos_y+3]=0;
                        map_status[pos_x+1][pos_y+3]=0;map_status[pos_x+4][pos_y+3]=0;
                    }
                    else
                    {
                        setBackgroundColor(0);setColor(0);locate(pos_x+2,pos_y+3);cout<<"ii";locate(pos_x,pos_y+3);cout<<"口口口";
                        map_status[pos_x-1][pos_y+2]=0;map_status[pos_x+2][pos_y+2]=0;
                        map_status[pos_x][pos_y+2]=0;map_status[pos_x+3][pos_y+2]=0;
                        map_status[pos_x+1][pos_y+2]=0;map_status[pos_x+4][pos_y+2]=0;
                    }
                    it=bombs.erase(it);it--;player1_bomb_cnt--;}

            if(map_status[pos_x-2][pos_y]==1&&direction==16)
            {
                if(map_status[pos_x-2][pos_y]!=1)
                {
                    setBackgroundColor(0);setColor(0);locate(pos_x-2,pos_y+1);cout<<"ii";
                    locate(pos_x-4,pos_y+1);cout<<"口";map_status[pos_x-4][pos_y+1]=0;map_status[pos_x-3][pos_y+1]=0;
                    locate(pos_x-4,pos_y);cout<<"口";map_status[pos_x-4][pos_y]=0;map_status[pos_x-3][pos_y]=0;
                    locate(pos_x-4,pos_y+2);cout<<"口";map_status[pos_x-4][pos_y-1]=0;map_status[pos_x-3][pos_y-1]=0;
                }
                else
                {
                    setBackgroundColor(0);setColor(0);locate(pos_x-2,pos_y+1);cout<<"ii";
                    locate(pos_x-2,pos_y+1);cout<<"口";map_status[pos_x-2][pos_y+1]=0;map_status[pos_x-3][pos_y+1]=0;
                    locate(pos_x-2,pos_y);cout<<"口";map_status[pos_x-2][pos_y]=0;map_status[pos_x-3][pos_y]=0;
                    locate(pos_x-2,pos_y+2);cout<<"口";map_status[pos_x-2][pos_y-1]=0;map_status[pos_x-3][pos_y-1]=0;
                }
            it=bombs.erase(it);it--;player1_bomb_cnt--;}

           if(map_status[pos_x+6][pos_y]==1&&direction==17)
           {
                if(map_status[pos_x+6][pos_y]!=1)
                {
                    setBackgroundColor(0);setColor(0);locate(pos_x+6,pos_y+1);cout<<"ii";
                    locate(pos_x+8,pos_y+1);cout<<"口";map_status[pos_x+7][pos_y+1]=0;map_status[pos_x+8][pos_y+1]=0;
                    locate(pos_x+8,pos_y);cout<<"口";map_status[pos_x+7][pos_y]=0;map_status[pos_x+8][pos_y]=0;
                    locate(pos_x+8,pos_y+2);cout<<"口";map_status[pos_x+7][pos_y-1]=0;map_status[pos_x+8][pos_y-1]=0;
                }
                else
                {
                    setBackgroundColor(0);setColor(0);locate(pos_x+6,pos_y+1);cout<<"ii";
                    locate(pos_x+6,pos_y+1);cout<<"口";map_status[pos_x+5][pos_y+1]=0;map_status[pos_x+6][pos_y+1]=0;
                    locate(pos_x+6,pos_y);cout<<"口";map_status[pos_x+5][pos_y]=0;map_status[pos_x+6][pos_y]=0;
                    locate(pos_x+6,pos_y+2);cout<<"口";map_status[pos_x+5][pos_y-1]=0;map_status[pos_x+6][pos_y-1]=0;
                }
                it=bombs.erase(it);it--;player1_bomb_cnt--;
            }

            if((pos_x>=bombpos2/100-3)&&(pos_x<=bombpos2/100+2)&&(pos_y>=bombpos2%100-1)&&(pos_y<=bombpos2%100+3)&&direction==14){status=0;}
            if((pos_x>=bombpos2/100-2)&&(pos_x<=bombpos2/100+3)&&(pos_y>=bombpos2%100-3)&&(pos_y<=bombpos2%100+1)&&direction==15){status=0;}
            if((pos_x>=bombpos2/100)&&(pos_x<=bombpos2/100+6)&&(pos_y>=bombpos2%100-1)&&(pos_y<=bombpos2%100+1)&&direction==16){status=0;}
            if((pos_x>=bombpos2/100+6)&&(pos_x<=bombpos2/100)&&(pos_y>=bombpos2%100-1)&&(pos_y<=bombpos2%100+1)&&direction==16){status=0;}
        }



        for (vector<bomb*>::iterator it=bombs2.begin(); it!=bombs2.end(); it++)
        {
            int position,direction,pos_x,pos_y;

            position=(*it)->run();direction=(*it)->get_position();

            pos_x=position/100;pos_y=position%100;
            if(map_status[position/100][position%100-3]==2&&direction==14){it=bombs2.erase(it);it--;player2_bomb_cnt--;setBackgroundColor(0);setColor(0);locate(pos_x+2,pos_y-1);cout<<"ii";}
            if(map_status[position/100][position%100+3]==2&&direction==15){it=bombs2.erase(it);it--;player2_bomb_cnt--;setBackgroundColor(0);setColor(0);locate(pos_x+2,pos_y+3);cout<<"ii";}
            if(map_status[position/100-4][position%100]==2&&direction==16){it=bombs2.erase(it);it--;player2_bomb_cnt--;setBackgroundColor(0);setColor(0);locate(pos_x-2,pos_y+1);cout<<"ii";}
            if((position/100==70)&&direction==17){it=bombs2.erase(it);it--;player2_bomb_cnt--;setBackgroundColor(0);setColor(0);locate(pos_x+6,pos_y+1);cout<<"ii";}

            if(map_status[pos_x+2][pos_y-2]==1&&direction==14)
            {
                if(map_status[pos_x+2][pos_y-2]!=1)
                {
                    setBackgroundColor(0);setColor(0);locate(pos_x+2,pos_y-1);cout<<"ii";
                    locate(pos_x,pos_y-2);cout<<"口口口";
                    map_status[pos_x-1][pos_y-3]=0;map_status[pos_x+2][pos_y-3]=0;
                    map_status[pos_x][pos_y-3]=0;map_status[pos_x+3][pos_y-3]=0;
                    map_status[pos_x+1][pos_y-3]=0;map_status[pos_x+4][pos_y-3]=0;

                }
                else
                {
                    setBackgroundColor(0);setColor(0);locate(pos_x+2,pos_y-1);cout<<"ii";
                    locate(pos_x,pos_y-1);cout<<"口口口";
                    map_status[pos_x-1][pos_y-2]=0;map_status[pos_x+2][pos_y-2]=0;
                    map_status[pos_x][pos_y-2]=0;map_status[pos_x+3][pos_y-2]=0;
                    map_status[pos_x+1][pos_y-2]=0;map_status[pos_x+4][pos_y-2]=0;
                }
                it=bombs2.erase(it);it--;player2_bomb_cnt--;}

                if(map_status[pos_x+2][pos_y+2]==1&&direction==15)
                {

                    if(map_status[pos_x+2][pos_y+2]!=1)
                    {
                        setBackgroundColor(0);setColor(0);locate(pos_x+2,pos_y+3);cout<<"ii";
                        locate(pos_x,pos_y+4);cout<<"口口口";
                        map_status[pos_x-1][pos_y+3]=0;map_status[pos_x+2][pos_y+3]=0;
                        map_status[pos_x][pos_y+3]=0;map_status[pos_x+3][pos_y+3]=0;
                        map_status[pos_x+1][pos_y+3]=0;map_status[pos_x+4][pos_y+3]=0;
                    }
                    else
                        {
                        setBackgroundColor(0);setColor(0);locate(pos_x+2,pos_y+3);cout<<"ii";
                        locate(pos_x,pos_y+3);cout<<"口口口";
                        map_status[pos_x-1][pos_y+2]=0;map_status[pos_x+2][pos_y+2]=0;
                        map_status[pos_x][pos_y+2]=0;map_status[pos_x+3][pos_y+2]=0;
                        map_status[pos_x+1][pos_y+2]=0;map_status[pos_x+4][pos_y+2]=0;
                    }
                    it=bombs2.erase(it);it--;player2_bomb_cnt--;}

                    if(map_status[pos_x-2][pos_y]==1&&direction==16)
                    {
                        if(map_status[pos_x-2][pos_y]!=1)
                        {
                            setBackgroundColor(0);setColor(0);locate(pos_x-2,pos_y+1);cout<<"ii";
                            locate(pos_x-4,pos_y+1);cout<<"口";map_status[pos_x-4][pos_y+1]=0;map_status[pos_x-3][pos_y+1]=0;
                            locate(pos_x-4,pos_y);cout<<"口";map_status[pos_x-4][pos_y]=0;map_status[pos_x-3][pos_y]=0;
                            locate(pos_x-4,pos_y+2);cout<<"口";map_status[pos_x-4][pos_y-1]=0;map_status[pos_x-3][pos_y-1]=0;
                        }
                    else
                    {
                        setBackgroundColor(0);setColor(0);locate(pos_x-2,pos_y+1);cout<<"ii";
                        locate(pos_x-2,pos_y+1);cout<<"口";map_status[pos_x-2][pos_y+1]=0;map_status[pos_x-3][pos_y+1]=0;
                        locate(pos_x-2,pos_y);cout<<"口";map_status[pos_x-2][pos_y]=0;map_status[pos_x-3][pos_y]=0;
                        locate(pos_x-2,pos_y+2);cout<<"口";map_status[pos_x-2][pos_y-1]=0;map_status[pos_x-3][pos_y-1]=0;
                    }
                    it=bombs2.erase(it);it--;player2_bomb_cnt--;
                }

                if(map_status[pos_x+6][pos_y]==1&&direction==17)
                {
                    if(map_status[pos_x+6][pos_y]!=1)
                    {
                        setBackgroundColor(0);setColor(0);
                        locate(pos_x+6,pos_y+1);cout<<"ii";
                        locate(pos_x+8,pos_y+1);cout<<"口";
                        map_status[pos_x+7][pos_y+1]=0;
                        map_status[pos_x+8][pos_y+1]=0;
                        locate(pos_x+8,pos_y);cout<<"口";map_status[pos_x+7][pos_y]=0;map_status[pos_x+8][pos_y]=0;
                        locate(pos_x+8,pos_y+2);cout<<"口";map_status[pos_x+7][pos_y-1]=0;map_status[pos_x+8][pos_y-1]=0;
                    }
                    else
                    {
                        setBackgroundColor(0);setColor(0);locate(pos_x+6,pos_y+1);cout<<"ii";
                        locate(pos_x+6,pos_y+1);cout<<"口";map_status[pos_x+5][pos_y+1]=0;map_status[pos_x+6][pos_y+1]=0;
                        locate(pos_x+6,pos_y);cout<<"口";map_status[pos_x+5][pos_y]=0;map_status[pos_x+6][pos_y]=0;
                        locate(pos_x+6,pos_y+2);cout<<"口";map_status[pos_x+5][pos_y-1]=0;map_status[pos_x+6][pos_y-1]=0;
                    }
                    it=bombs2.erase(it);it--;player2_bomb_cnt--;
                }

                if((pos_x>=get_position/100-3)&&(pos_x<=get_position/100+2)&&(pos_y>=get_position%100-1)&&(pos_y<=get_position%100+3)&&direction==14){status=0;}
                if((pos_x>=get_position/100-2)&&(pos_x<=get_position/100+3)&&(pos_y>=get_position%100-3)&&(pos_y<=get_position%100+1)&&direction==15){status=0;}
                if((pos_x>=get_position/100)&&(pos_x<=get_position/100+6)&&(pos_y>=get_position%100-1)&&(pos_y<=get_position%100+1)&&direction==16){status=0;}
                if((pos_x>=get_position/100+6)&&(pos_x<=get_position/100)&&(pos_y>=get_position%100-1)&&(pos_y<=get_position %100+1)&&direction==16){status=0;}
        }

        cnt=0;

        //update the map status
        for(int j=0; j<map_height; j++)
        {
            for(int i=0; i<map_width; i++)
            {
                *(player1_tank.Getch()+cnt)= map_status[i][j];
                *(player2_tank.Getch()+cnt)= map_status[i][j];
                cnt++;
            }
        }
        player1_tank.update_map_status();
        player2_tank.update_map_status();
    }
    return 0;
}

