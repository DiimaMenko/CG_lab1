#include "mypoint.h"

MyPoint::MyPoint()
{

}

MyPoint::MyPoint(double xpos, double ypos){
    xp = xpos;
    yp = ypos;
}

double MyPoint::x(){
    return xp;
}

double MyPoint::y(){
    return yp;
}

void MyPoint::setX(double x){
    xp = x;
}

void MyPoint::setY(double y){
    yp = y;
}

bool operator==(const MyPoint &p1, const MyPoint &p2){
    return p1.xp == p2.xp && p1.yp == p2.yp;
}

bool operator!=(const MyPoint &p1, const MyPoint &p2){
    return p1.xp != p2.xp || p1.yp != p2.yp;
}
