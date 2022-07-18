#include <stdio.h>

int main()
{
    float speed,capacity,time;
    printf("Please input the downloading speed(Mb)&the file capacity(MB):\n");
    scanf("%f %f",&speed,&capacity);
    time = capacity*8.0/speed;
    printf("At %.2f megabits per second, a file of %.2f megabytes\ndownloads in %.2f seconds.",speed,capacity,time);
    return 0;
}
