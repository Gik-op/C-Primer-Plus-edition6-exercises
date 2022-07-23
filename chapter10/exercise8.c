#include <stdio.h>

void copy_ptr(double*,const double*,int);
void show_arr(const double*,int);

int main() {
    double test[7]={1.1,2.2,3.3,4.4,5.5,6.6,7.7};
    double copy[3];
    copy_ptr(copy,test+2,3);
    show_arr(test,7);
    show_arr(copy,3);
    return 0;
}

void copy_ptr(double* aim,const double* base,int num)
{
    int count;
    for(count=0;count<num;count++)
        *(aim+count)=*(base+count);
}
void show_arr(const double* arr,int num)
{
    for(int i=0;i<num;i++)
        printf("%4.1f ",*(arr+i));
    printf("\n");
}