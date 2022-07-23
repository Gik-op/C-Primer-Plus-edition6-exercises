#include <stdio.h>

void invert(double*,int);
void invert2(double*,int);
void show_arr(const double*,int);

int main()
{
    double test[5]={1.0,2.0,3.0,4.0,5.0};
    show_arr(test,5);
    invert(test,5);
    show_arr(test,5);
    invert2(test,5);
    show_arr(test,5);
    return 0;
}

void invert(double* arr,int num)//思路一，建立数组再进行转换，转换两次
{
    double new[num];
    for(int i=0;i<num;i++)
        new[num-1-i]=arr[i];
    for(int n=0;n<num;n++)
        arr[n]=new[n];
}

void invert2(double* arr,int num)//思路二，从首尾开始转换，效率更高
{
    double temp;
    for(int i=0;i<num/2;i++)
    {
        temp=arr[num-i-1];
        arr[num-i-1]=arr[i];
        arr[i]=temp;
    }
}

void show_arr(const double* arr,int num)
{
    for(int i=0;i<num;i++)
        printf("%4.1f",*(arr+i));
    printf("\n");
}
