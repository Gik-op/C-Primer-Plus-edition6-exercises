#include <stdio.h>
#include <time.h>

void time_circle(double time);

int main()
{
    double seconds;
    printf("Hello, please enter the number of seconds:");
    while(scanf("%lf",&seconds)==1)
    {
        time_circle(seconds);
        printf("Seconds you want to delay(q to quit):");
    }
    puts("Bye.");
    return 0;
}

void time_circle(double time)
{
    double delay=0;
    double begin=(double)clock();
    while(delay<time)
    {
        double now=(double)clock();
        delay=(now-begin)/CLOCKS_PER_SEC;
        printf("Not delay enough!\n");
    }
    printf("Delay %f seconds.\n",delay);
}
