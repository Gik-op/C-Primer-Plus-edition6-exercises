//pe12-2b.c
// 与pe12-2a.c一起编译
#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
    int mode=0,set=0;
    double distance;
    double fuel;
    int *ptr=&mode;
    double *dis=&distance;
    double *fu=&fuel;

    printf("Enter 0 for metric mode,1 for US mode:");
    scanf("%d",&set);
    while(set>=0)
    {
        set_mode(set,ptr);
        get_info(mode,dis,fu);
        show_info(mode,distance,fuel);
        printf("Enter 0 for metric mode,1 for US mode");
        printf("(-1 to quit):");
        scanf("%d",&set);
    }
    printf("Done.\n");
    return 0;
}
