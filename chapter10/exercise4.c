#include <stdio.h>

int re_max_sub(const double*,int);
void show_arr(const double*,int);

int main()
{
    int max;
    double number[10]={1,-3,4.8,0.9,-1.3,2,6,7.1,-2.4,3.2};
    max=re_max_sub(number,10);
    printf("The biggest number in the array has subscript value %d.\n",max);
    show_arr(number,10);
    return 0;
}

int re_max_sub(const double* arr,int num)
{
    double max=arr[0];
    int rank;
    for(int i=0;i<num;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            rank=i;
        }
    }
    return rank;
}

void show_arr(const double* arr,int num)
{
    for(int i=0;i<num;i++)
        printf("%5.1f",*(arr+i));
    printf("\n");
}
