#ifndef SEGMENT_H
#define SEGMENT_H

#include <mypoint.h>
#include <QtMath>
#include <QString>

#define PI 3.14159265
#define INF -10000000
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
#define min(X, Y) (((X) < (Y)) ? (X) : (Y))

class segment
{
private:
    MyPoint *startPoint;
    MyPoint *endPoint;
    MyPoint *intersectPoint;
    float A;
    float B;
    float C;
public:
    segment();
    segment(float x1, float y1, float x2, float y2);
    void setSegment(float x1, float y1, float x2, float y2);
    MyPoint *getStart();
    MyPoint *getEnd();
    float getA();
    float getB();
    float getC();

    bool equal(segment *seg);
    bool parallelLines (segment *seg);
    bool intersect (segment *seg);
    bool range (segment *seg, MyPoint *inter);
    double Angle(segment *seg);
    long double getDet (long double a, long double b, long double c, long double d);
    QString test(segment *seg);
    ~segment(){}
};

#endif // SEGMENT_H
