#include "myfunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int myfunc(int b) {
    return b+4;
}

int fibonachi(int num) {
    int prev = 1;
    int next = 1;

    if (num < 0)
        return 0;

    if (num <= 2)
        return num;

    int i = 2;
    while (i < num) {
        next += prev;
        prev = next - prev;
        i++;
    }

    return next;
}


double f(int a,int b,int c)
{

double d,x1 = 0,x2 = 0, t[2];
d =(b*b)-4*a*c;
    if (d>0)
{
    if (a==0)
    {
        x1 = (-c)/(b);
        return x1;
    }
    x1=(-b+sqrt(d))/(2*a);
    x2=(-b-sqrt(d))/(2*a);
    if (x1 > x2)
    {
        double r;
        r = x2;
        x2 = x1;
        x1 = r;
    }

    t[0] = x1; t[1] = x2;
    return *t;
}
    if (d<0)
{
    return INFINITY;
}
    if (d==0)
    {
        if (a==0 && b==0)
            return INFINITY;
        x1=(-b)/(2*a);
        return x1;
   }
    return -777;
}


