//pe12-2b.c中的函数原型
#include <stdio.h>
#include "pe12-2a.h"

void set_mode(int set)
{
    if(set==0||set==1)
        mode=set;
    else if(mode==1)
        printf("Invalid mode specified.Mode 1(US) used.\n");
    else if(mode==0)
        printf("Invalid mode specified.Mode 0(EUR) used.\n");
}

void get_info(void)
{
    if(mode==0)
    {
        printf("Enter distance travelled in kilometers:");
        scanf("%lf",&distance);
        printf("Enter fuel consumed in liters:");
        scanf("%lf",&fuel);
    }
    else
    {
        printf("Enter distance travelled in miles:");
        scanf("%lf",&distance);
        printf("Enter fuel consumed in gallons:");
        scanf("%lf",&fuel);
    }
}

void show_info(void)
{
    if(mode==0)
        printf("Fuel consumption is %.2f liters per 100 km.\n",fuel/distance*100);
    else
        printf("Fuel consumption is %.2f miles per gallon.\n",distance/fuel);
}
