#include "segment.h"

segment::segment(){
    this->startPoint = new MyPoint(0, 0);
    this->endPoint = new MyPoint(0, 0);
    this->A = this->endPoint->y() - this->startPoint->y();
    this->B = this->endPoint->x() - this->startPoint->x();
    this->C = this->startPoint->x() * this->endPoint->y() - this->endPoint->x() * this->startPoint->y();
}

segment::segment(float x1, float y1, float x2, float y2){
    this->startPoint = new MyPoint(x1, y1);
    this->endPoint = new MyPoint(x2, y2);
    this->A = this->endPoint->y() - this->startPoint->y();
    this->B = this->endPoint->x() - this->startPoint->x();
    this->C = this->startPoint->x() * this->endPoint->y() - this->endPoint->x() * this->startPoint->y();
}

void segment::setSegment(float x1, float y1, float x2, float y2){
    this->startPoint->setX(x1);
    this->startPoint->setY(y1);
    this->endPoint->setX(x2);
    this->endPoint->setY(y2);
    this->A = this->endPoint->y() - this->startPoint->y();
    this->B = this->endPoint->x() - this->startPoint->x();
    this->C = this->startPoint->x() * this->endPoint->y() - this->endPoint->x() * this->startPoint->y();
}

MyPoint* segment::getEnd(){
    return this->endPoint;
}

MyPoint* segment::getStart(){
    return this->startPoint;
}

float segment::getA(){
    return this->A;
}

float segment::getB(){
    return this->B;
}

float segment::getC(){
    return this->C;
}

bool segment::equal(segment *seg){
    return abs (getDet (this->A, this->C, seg->getA(), seg->getC())) == 0
            && abs (getDet (this->B, this->C, seg->getB(), seg->getC())) == 0;
}

long double segment::getDet(long double a, long double b, long double c, long double d){
    return a * d - b * c;
}

bool segment::parallelLines (segment *seg)
{
    return getDet (this->A, this->B, seg->getA(), seg->getB()) == 0;
}

bool segment::intersect(segment *seg)
{
    long double zn = getDet (this->A, this->B, seg->getA(), seg->getB());
    MyPoint *inter = new MyPoint(getDet (getC(), getB(), seg->getC(), seg->getB()) / zn, - getDet (this->A, this->C, seg->getA(), seg->getC()) / zn);
    if(range(seg, inter)){
        this->intersectPoint = inter;
        return true;
    }
    return false;
}

bool segment::range (segment *seg ,MyPoint *inter)
{
    bool    x1 = false,
            y1 = false,
            x2 = false,
            y2 = false,
            result = false;
    double  maxX1 = max(getStart()->x(), getEnd()->x()),
            maxY1 = max(getStart()->y(), getEnd()->y()),
            minX1 = min(getStart()->x(), getEnd()->x()),
            minY1 = min(getStart()->y(), getEnd()->y()),

            maxX2 = max( seg->getStart()->x(), seg->getEnd()->x()),
            maxY2 = max( seg->getStart()->y(), seg->getEnd()->y()),
            minX2 = min( seg->getStart()->x(), seg->getEnd()->x()),
            minY2 = min( seg->getStart()->y(), seg->getEnd()->y());

    if(inter->x() <= maxX1 && inter->x() >= minX1)
        x1 = true;
    if(inter->y() <= maxY1 && inter->y() >= minY1)
        y1 = true;
    if(inter->x() <= maxX2 && inter->x() >= minX2)
        x2 = true;
    if(inter->y() <= maxY2 && inter->y() >= minY2)
        y2 = true;
    result = x1 && x2 && y1 && y2;
    if(result)
        return true;
    else
        return false;
}

double segment::Angle(segment *seg)
{
    if((this->B * seg->getA() - seg->getB() * this->A) < 0)
        return	360 - acos((this->B * seg->getB() + this->A * seg->getA()) /
                           (sqrt(this->A * this->A + this->B * this->B) *
                            sqrt(seg->getA() * seg->getA() + seg->getB() * seg->getB()))) * 180.0 / PI;
    else
        return	acos((this->B * seg->getB() + this->A * seg->getA()) /
                     (sqrt(this->A * this->A + this->B * this->B) *
                      sqrt(seg->getA() * seg->getA() + seg->getB() * seg->getB()))) * 180.0 / PI;
}

QString segment::test (segment *seg){
    QString temp;
    if(equal(seg))
    {
        temp.push_back("Відрізки лежать на одній прямій");
        if (range(seg, this->startPoint) || range(seg, this->endPoint)){
            temp.push_back("\nВідрізки перетинаються");
            return temp;
        }
        else{
            temp.push_back("\nВідрізки не перетинаються");
            return temp;
        }
    }
    if(parallelLines(seg)){
        temp.push_back("Відрізки паралельні");
        return temp;
    }
    else
    {
        if(intersect(seg)){
            temp.push_back("Відрізки перетинаються в точці: Х = ");
            temp.push_back(QString::number(this->intersectPoint->x()));
            temp.push_back(" Y = ");
            temp.push_back(QString::number(this->intersectPoint->y()));
        }
        else{
            temp.push_back("Відрізки не перетинаються");
        }
    }
    temp.push_back("\nКут  між прямими: ");
    temp.push_back(QString::number(Angle(seg)));
    return temp;
}
