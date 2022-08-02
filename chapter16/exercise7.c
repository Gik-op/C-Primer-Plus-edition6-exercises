#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void show_array(const double ar[],int n);
double * new_d_array(int n,...);

int main()
{
    double *p1,*p2;
    p1 = new_d_array(5,1.2,2.3,3.4,4.5,5.6);
    p2 = new_d_array(4,100.0,20.00,8.08,-1890.0);
    show_array(p1,5);
    show_array(p2,4);
    free(p1);
    free(p2);
    return 0;
}

double * new_d_array(int n,...)
{
    double *array=(double *)malloc(n*sizeof(double));
    va_list ap;
    va_start(ap,n);
    for(int index=0;index<n;index++)
        *(array+index)= va_arg(ap,double);
    va_end(ap);
    return array;
}

void show_array(const double ar[],int n)
{
    for(int index=0;index<n;index++)
    {
        printf("%.2f ",ar[index]);
        if(index%5==4)
            printf("\n");
    }
    if(n%5!=0)
        printf("\n");
}

