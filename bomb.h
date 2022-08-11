#ifndef BOMB_H
#define BOMB_H
#include "player.h"

class bomb
{
    public:
        bomb(road *m);
        void set_direction(int direction) { d=direction;}
        int get_position(){return d;}
        void set_position(int dx, int dy) { x=dx; y=dy; }
        virtual ~bomb();
        int x;
        int d;
        int y;
        int speed=2500;
        int bomb_cnt=0;
        int chk2[80][41];
        int run();

void Clear();
    protected:

    private:
    void show();

};

#endif // BOMB_H
