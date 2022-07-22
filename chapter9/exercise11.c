#include <stdio.h>

unsigned long long Fibonacci(int);

int main() {
    int rank;
    unsigned long long number;
    printf("Hello, please enter the rank in Fibonacci,and I will show you the number:\n");
    while((scanf("%llu",&rank))==1)
    {
        number= Fibonacci(rank);
        printf("The number rank %d is %llu.\n",rank,number);
        printf("\nHello, please enter the rank in Fibonacci,and I will show you the number(q to quit):\n");
    }
    printf("Bye.\n");
    return 0;
}

unsigned long long Fibonacci(int rank)
{
    unsigned long long fibo,fibo_p,fibo_n;
    int count;
    if(rank==1||rank==2)
        fibo_n=1;
    else
    {
        fibo=1;
        fibo_p=1;
        for(count=2;count<rank;count++)
        {
            fibo_n=fibo+fibo_p;
            fibo_p=fibo;
            fibo=fibo_n;
        }
    }
    return fibo_n;
}
