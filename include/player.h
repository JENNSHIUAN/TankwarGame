#ifndef PLAYER_H
#define PLAYER_H
#include "road.h"

class player
{


    public:
        player(road *pbd,int x,int y);
        int Move(int key);
        int mp_x;
        int mp_y;
        int direction;
        int i;
        int fg;
        road *pm;
        char * Getch() { return all_m2;}
        void sendec(int a[]);
        void run(int key);
        int update_map_status();
        int chk2[80][41];
        char  all_m2[3280];
        virtual ~player();
    protected:

    private:
        void show(int i);
        void Clear();

};

#endif // PLAYER_H
