#include <stdio.h>

void sum_3(int*,int*,int*,int);
void show_arr(const int*,int);

int main() {
    printf("Hello, World!\n");
    int add1[4]={2,4,5,8};
    int add2[4]={1,0,4,6};
    int sum[4];
    sum_3(add1,add2,sum,4);
    show_arr(add1,4);
    show_arr(add2,4);
    show_arr(sum,4);
    return 0;
}
 void sum_3(int* arr1,int* arr2,int* sum,int size)
{
    for(int n=0;n<size;n++)
        sum[n]=arr1[n]+arr2[n];
}

void show_arr(const int* arr,int num)
{
    for(int i=0;i<num;i++)
        printf("%4d",*(arr+i));
    printf("\n");
}

