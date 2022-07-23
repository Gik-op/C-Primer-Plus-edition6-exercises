#include <stdio.h>

double re_devi(const double*,int);

int main()
{
    double deviation;
    double array[10]={1.0,0.2,3.1,4.4,1.8,9.9,6.7,-0.3,0.77,6.4};
    deviation= re_devi(array,10);
    printf("The difference between the MAX and MIN in the array is %.2f.\n",deviation);
    return 0;
}

double re_devi(const double* arr,int num)
{
    double min,max;
    min=max=arr[0];
    for(int i=0;i<num;i++)
    {
        if(arr[i]<min)
            min=arr[i];
        if(arr[i]>max)
            max=arr[i];
    }
    return max-min;
}
