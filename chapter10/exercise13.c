#include <stdio.h>
#define ROW 5
#define LINE 3

void store_arr(double arr[][ROW],int line);//读取数据，可处理错误输入
double aver_arr(const double* arr,int row);//处理每组平均值
double aver_all(const double arr[][ROW],int line);//处理总平均值
double find_max(const double arr[][ROW],int line);//查找最大数据
void show_arr2(int line,int row,double arr[line][row]);//显示输入

int main() {
    double array[LINE][ROW];
    double aver[LINE];
    double average,max;
    printf("Please enter 15 numbers(3 groups,5 numbers in each group).\n");
    store_arr(array,LINE);
    show_arr2(LINE,ROW,array);
    printf("The average of every group is\n");
    for(int count=0;count<LINE;count++)
    {
       aver[count]= aver_arr(array[count],ROW);
       printf("Average: Group%d %.2f\n",count+1,aver[count]);
    }
    average=aver_all(array,LINE);
    printf("The average of all the numbers is %.2f.\n",average);
    max= find_max(array,LINE);
    printf("The biggest number in all the 15 numbers is %f.\n",max);
    return 0;
}

void store_arr(double arr[][ROW],int line)
{
    for(int l=0;l<line;l++)
    {
        for(int r=0;r<ROW;r++)
        {
            while(scanf("%lf",&arr[l][r])!=1)
            {
                char ch;
                while((ch=getchar())!='\n')
                    putchar(ch);//读取错误的输入数据并丢弃，实际目的是为了清空缓冲区
                printf(" is not an integer.Input again!\n");
            }
        }
    }
}

double aver_arr(const double* arr,int row)
{
    double sum=0.0;
    for(int i=0;i<row;i++)
        sum+=arr[i];
    return sum/row;
}

double aver_all(const double arr[][ROW],int line)
{
    double total=0.0;
    for(int n=0;n<line;n++)
        for(int m=0;m<ROW;m++)
            total+=arr[n][m];
    return total/(line*ROW);
}

double find_max(const double arr[][ROW],int line)
{
    double max = arr[0][0];
    for (int n = 0; n < line; n++)
    {
        for (int m = 0; m < ROW; m++)
        {
            if (arr[n][m] > max)
                max = arr[n][m];//比较麻烦的算法，需要逐一对比
        }
    }
    return max;
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