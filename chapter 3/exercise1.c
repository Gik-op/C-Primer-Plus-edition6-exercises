#include <stdio.h>

int main()
{
    int i=2147483647;//上溢会回到最小值（负值）重新开始
    unsigned int j=4294967295;//上溢会回到最小值（零值）重新开始
    printf("%d %d %d\n",i,i+1,i+2);
    printf("%d %d %d\n",j,j+1,j+2);
    double small=0.1234E-10;
    printf("%e",small/2.00);
    return 0;
}
