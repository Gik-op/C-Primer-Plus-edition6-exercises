#include <stdio.h>
#include <math.h>

#define DEG_TO_RAD (4*atan(1)/180)

typedef struct polar{
    double r;
    double angel;//In degree
}polar_v;

typedef struct rect{
    double x;
    double y;
}rect_v;

rect_v polar2rect(const polar_v *base);

int main()
{
    polar_v base;
    rect_v result;
    puts("Hello, please enter a polar coordinate(r degree):");
    while(scanf("%lf %lf",&base.r,&base.angel)==2)
    {
        result= polar2rect(&base);
        printf("The rectangular coordinate:\n x: %.2f  y:%.2f\n",result.x,result.y);
        puts("Your polar coordinate(q to quit):");
    }
    puts("Bye.");
    return 0;
}

rect_v polar2rect(const polar_v *base)
{
    double radian=(base->angel)*DEG_TO_RAD;
    rect_v target;
    target.x=base->r*cos(radian);
    target.y=base->r* sin(radian);
    return target;
}
