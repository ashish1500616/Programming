#include "circle.h"
Circle::Circle()
{
    radius=0;
    pi=3.142;
}
Circle::Circle(double r)
{
    radius =r;
    pi=3.142;
}

double Circle::area()
{
    return pi * radius * radius ;
}
double Circle::perimeter()
{
    return 2 * pi * radius;
}