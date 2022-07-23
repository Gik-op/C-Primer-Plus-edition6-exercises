#include <stdio.h>

void copy_arr(double*,const double*,int);
void copy_ptr(double*,const double*,int);
void copy_ptrs(double*,double*,double*);
void show_arr(const double*,int);

int main()
{
    double source[5] = {1.1,2.2,3.3,4.4,5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1,source,5);
    copy_ptr(target2,source,5);
    copy_ptrs(target3,source,source+5);
    show_arr(target1,5);
    show_arr(target2,5);
    show_arr(target3,5);
    return 0;
}

void copy_arr(double* aim,const double* base,int num)
{
    int count;
    for(count=0;count<num;count++)
        aim[count]=base[count];
}
void copy_ptr(double* aim,const double* base,int num)
{
    int count;
    for(count=0;count<num;count++)
        *(aim+count)=*(base+count);
}
void copy_ptrs(double* aim,double* start,double* end)
{
    for(int p=0;start<end;start++,p++)
        *(aim+p)=*start;
}

void show_arr(const double* arr,int num)
{
    for(int i=0;i<num;i++)
        printf("%4.1f",*(arr+i));
    printf("\n");
}