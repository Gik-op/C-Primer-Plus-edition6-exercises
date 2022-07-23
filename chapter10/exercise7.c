#include <stdio.h>

void copy_arr(double*,const double*,int);
void show_arr2(int line,int row,double arr[line][row]);

int main() {
    double test[2][4]=
            {
                    {1.1,2.2,3.3,4.4},
                    {5.5,6.6,7.7,8.8}
            };
    double aim[2][4];
    for(int n=0;n<2;n++)
        copy_arr(aim[n],test[n],4);
    show_arr2(2,4,test);
    printf("The result of copy.\n");
    show_arr2(2,4,aim);
    return 0;
}

void copy_arr(double* aim,const double* base,int num)
{
    int count;
    for(count=0;count<num;count++)
        aim[count]=base[count];
}

void show_arr2(int line,int row,double arr[line][row])
{
    for(int n=0;n<line;n++)
    {
        for(int m=0;m<row;m++)
            printf("%4.2f  ",arr[n][m]);
        printf("\n");
    }
}
