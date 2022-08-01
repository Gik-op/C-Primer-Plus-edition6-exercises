#include <stdio.h>

#define harmo_mean(x,y) (1.0/((1.0/(x)+1.0/(y))/2.0))

int main()
{
    double x,y,harmonic;
    puts("Hello, please enter two numbers(q to quit):");
    while(scanf("%lf %lf",&x,&y)==2)
    {
        harmonic= harmo_mean(x,y);
        printf("The harmonic mean of %.2lf and %.2lf is %.4lf.\n",x,y,harmonic);
        puts("Two numbers please(q to quit):");
    }
    puts("Bye.");
    return 0;
}
