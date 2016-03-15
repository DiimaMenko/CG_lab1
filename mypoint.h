#ifndef MYPOINT_H
#define MYPOINT_H


class MyPoint
{
private:
    double xp;
    double yp;
public:
    MyPoint();
    MyPoint(double xpos, double ypos);
    double x();
    double y();
    void setX(double x);
    void setY(double y);

    friend bool operator==(const MyPoint &, const MyPoint &);
    friend bool operator!=(const MyPoint &, const MyPoint &);
};

#endif // MYPOINT_H
