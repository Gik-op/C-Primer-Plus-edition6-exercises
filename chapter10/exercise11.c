#include <stdio.h>
#define ROW 5

void show_arr2(int line,int arr[][ROW]);
void doub_arr2(int line,int arr[][ROW]);

int main()
{

    int test[3][5]=
            {
                    {1,2,3,4,5},
                    {9,8,7,6,5},
                    {3,4,5,6,7}
            };
    show_arr2(3,test);
    doub_arr2(3,test);
    printf("After double.....\n");
    show_arr2(3,test);
    return 0;
}

void show_arr2(int line,int arr[][ROW])
{
    for(int n=0;n<line;n++)
    {
        for(int m=0;m<ROW;m++)
            printf("%-4d",arr[n][m]);
        printf("\n");
    }
}

void doub_arr2(int line,int arr[][ROW])
{
    for(int n=0;n<line;n++)
        for(int m=0;m<ROW;m++)
            arr[n][m]*=2;
}