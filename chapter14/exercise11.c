#include <stdio.h>
#include <math.h>

#define times 4
#define SIZE 100

void show_st(double arr[],int size);
double my_cube(double x){return x*x*x;}
double triple(double x){return 3*x;}
double* transform(double arr1[],double arr2[],int size,double(*ptr)(double));

int main()
{
    double (*ptr[times])(double)={sin,sqrt, my_cube,triple};
    double arr1[SIZE],arr2[SIZE];
    for(int i=0;i<SIZE;i++)
        arr1[i]=i+1;
    show_st(arr1,SIZE);
    for(int function=0;function<times;function++)
    {
        printf("Function %d\n",function);
        transform(arr1,arr2,SIZE,ptr[function]);
        show_st(arr2,SIZE);
        printf("\n");
    }
    return 0;
}

double* transform(double arr1[],double arr2[],int size,double(*ptr)(double))
{
    for(int index=0;index<size;index++)
        arr2[index]=ptr(arr1[index]);
    return arr2;
}

void show_st(double arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%-5.2f ",arr[i]);
        if(i%10==9)
            printf("\n");
    }
}
