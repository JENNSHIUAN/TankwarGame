#ifndef ROAD_H
#define ROAD_H


class road
{
    public:
        road(int x,int y);
        void Map();
        virtual ~road();

        int Getrx() { return m_x; }
        int Getly() { return m_y; }
        char * Getch() { return all_m;}
        void  sendchk(int b[][41] );
        char all_m[3280];
    protected:
        int m_x;
        int m_y;

        int chk[80][41];
    void Big(int x,int y);
    void Min(int x,int y);
    void Small(int x,int y);
    void Background(int h,int w);
    private:
        int fk();

};

#endif // ROAD_H
