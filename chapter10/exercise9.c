#include <stdio.h>

void show_arr2(int line,int row,double arr[line][row]);
void copy_arr2(int line,int row,double arr[line][row],double copy[line][row]);

int main() {
    double test[3][5]=
            {
                    {1.1,2.2,3.3,4.4,5.5},
                    {1.2,2.2,3.2,4.2,5.2},
                    {1.3,2.3,3.3,4.3,5.3}
            };
    double copy[3][5];
    copy_arr2(3,5,test,copy);
    show_arr2(3,5,test);
    printf("\n");
    show_arr2(3,5,copy);
    return 0;
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
void copy_arr2(int line,int row,double arr[line][row],double copy[line][row])
{
    for(int n=0;n<line;n++)
        for(int m=0;m<row;m++)
            copy[n][m]=arr[n][m];
}