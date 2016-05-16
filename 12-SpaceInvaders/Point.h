#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();

        void setXY();
        void printXY();
        int getX();
        int getY();
        char ship = '%';
        int _x = 100, _y = 100;
        int life = 10;
        bool go = false; //to not repeat the same bullet


};

#endif // POINT_H
