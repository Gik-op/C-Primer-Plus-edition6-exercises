#include <stdio.h>
#define ROW 5
#define LINE 3

void store_arr(int line,int row,double arr[line][row]);
double aver_arr(const double* arr,int row);
double aver_all(int line,int row,double arr[line][row]);
double find_max(int line,int row,double arr[line][row]);

int main() {
    double array[LINE][ROW];
    double aver[LINE];
    double average,max;
    printf("Please enter 15 numbers(3 groups,5 numbers in each group).\n");
    store_arr(LINE,ROW,array);
    printf("The average of every group is\n");
    for(int count=0;count<LINE;count++)
    {
        aver[count]= aver_arr(array[count],ROW);
        printf("Average: Group%d %.2f\n",count+1,aver[count]);
    }
    average=aver_all(LINE,ROW,array);
    printf("The average of all the numbers is %.2f.\n",average);
    max= find_max(LINE,ROW,array);
    printf("The biggest number in all the 15 numbers is %f.\n",max);
    return 0;
}

void store_arr(int line,int row,double arr[line][row])
{
    for(int l=0;l<line;l++)
    {
        for(int r=0;r<ROW;r++)
        {
            while(scanf("%lf",&arr[l][r])!=1)
            {
                char ch;
                while((ch=getchar())!='\n')
                    putchar(ch);
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

double aver_all(int line,int row,double arr[line][row])
{
    double total=0.0;
    for(int n=0;n<line;n++)
        for(int m=0;m<row;m++)
            total+=arr[n][m];
    return total/(line*row);
}

double find_max(int line,int row,double arr[line][row])
{
    double max=arr[0][0];
    for(int n=0;n<line;n++)
    {
        for(int m=0;m<row;m++)
        {
            if(arr[n][m]>max)
                max=arr[n][m];
        }
    }
    return max;
}
