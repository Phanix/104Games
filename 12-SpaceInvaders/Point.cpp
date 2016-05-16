#include "Point.h"
#include<iostream>
using namespace std;
Point::Point()
{
    //ctor
}

Point::~Point()
{
    //dtor
}
 void Point::setXY(bool setX){
    if(!setX){
        int x;
        cout << "Enter a value for x : ";
        cin >> x;
        _x = x;
    }
    else{
        int y;
        cout << "Enter a value for y : ";
        cin >> y;
        _y = y;
    }
}

void Point::printXY(){
    cout << "The value of x : " << _x << "\n" << "The value of y : " << _y << endl;
}
