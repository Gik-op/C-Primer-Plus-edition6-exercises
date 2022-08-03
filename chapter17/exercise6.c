#include <stdio.h>
#include <stdbool.h>

void RankArray(int size,int *arr);
bool InArray(int size,const int arr[size],int aim);

int main()
{
    int test[9]={1,2,3,4,5,6,7,8,9};
    if(InArray(9,test,9))
        printf("Find the number %d\n",1);
    else
        printf("Not find the number %d\n",1);
    return 0;
}
//use this function before using InArray
void RankArray(int size,int *arr)
{
    int temp;
    for(int i=0;i<size-1;i++)
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[i])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
}

//Be sure the array in ascending order
bool InArray(int size,const int arr[size],int aim)
{
    int floor=0,upper=size-1;
    while(floor<upper-1)
    {
        int now=(floor+upper)/2;
        if(arr[now]<aim)
            floor=now;
        else if(arr[now]>aim)
            upper=now;
        else
            return true;
    }
    if(floor==upper-1)
        if(arr[upper]==aim)
            return true;
    return false;
}
