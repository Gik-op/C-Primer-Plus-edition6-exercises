//pe12-2b.c中的函数原型
#include <stdio.h>
#include "pe12-2a.h"

void set_mode(int set,int *ptr)//采用指针，在实际的mode和输入的set之间搭建桥梁
{
   if(set!=1&&set!=0)
   {
       if(*ptr==1)
           printf("Invalid mode specified.Mode 1(US) used.\n");
       else
           printf("Invalid mode specified.Mode 0(EUR) used.\n");
   }
   else
       *ptr=set;
}

void get_info(int mode,double *dis,double *fu)//通过指针修改主函数中的值
{
    if(mode==0)
    {
        printf("Enter distance travelled in kilometers:");
        scanf("%lf",dis);
        printf("Enter fuel consumed in liters:");
        scanf("%lf",fu);
    }
    else
    {
        printf("Enter distance travelled in miles:");
        scanf("%lf",dis);
        printf("Enter fuel consumed in gallons:");
        scanf("%lf",fu);
    }
}

void show_info(int mode,double distance,double fuel)
{
    if(mode==0)
        printf("Fuel consumption is %.2f liters per 100 km.\n",fuel/distance*100);
    else
        printf("Fuel consumption is %.2f miles per gallon.\n",distance/fuel);
}