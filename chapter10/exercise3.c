#include <stdio.h>

int re_max(const int*,int);

int main()
{
    int max;
    int number[10]={1,-3,8,9,-13,2,6,7,-24,32};
    max=re_max(number,10);
    printf("The biggest number in the array is %d.\n",max);
    return 0;
}

int re_max(const int* arr,int num)
{
    int max=arr[0];
    for(int i=0;i<num;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}
