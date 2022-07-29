#include <stdio.h>
#include "definition.h"

#define flight_num 4

int main()
{
    char answer;
    char choice_f[MAX];
    struct plane flight[SIZE]={
            {1,0,false},
            {2,0,false},
            {3,0,false},
            {4,0,false},
            {5,0,false},
            {6,0,false},
            {7,0,false},
            {8,0,false},
            {9,0,false},
            {10,0,false},
            {11,0,false},
            {12,0,false},
    };
    struct plane company[flight_num][SIZE];
    for(int i=0;i<flight_num;i++)
        for(int j=0;j<SIZE;j++)
            company[i][j]=flight[j];//初始化
    printf("Hey,choose the number of your plane(102 311 444 519)or press q to quit:");
    while(1)
    {
        int number;
        gets(choice_f);
        number=strtol(choice_f,NULL,10);
        if(number==102||number==311||number==444||number==519)
        {
            int yours;
            switch(number)
            {
                case 102:yours=0;break;
                case 311:yours=1;break;
                case 444:yours=2;break;
                case 519:yours=3;break;
            }
            menu(number);
            answer=get_a();
            while(answer!='f')
            {
                switch(answer)
                {
                    case'a':
                        choose_a(SIZE,company[yours]);
                        break;
                    case'b':
                        choose_b(SIZE,company[yours]);
                        break;
                    case'c':
                        choose_c(SIZE,company[yours]);
                        break;
                    case'd':
                        choose_d(SIZE,&company[yours]);
                        break;
                    case'e':
                        choose_e(SIZE,&company[yours]);
                        break;
                    default:
                        choose_g(SIZE,&company[yours]);
                        break;
                }
                menu(number);
                answer=get_a();
            }
            printf("Choose the number of your plane(102 311 444 519) or press q to quit:");
        }
        else if(choice_f[0]=='q')
            break;
        else
            printf("Wrong input! Input again:");
    }
    printf("Finished!\n");
    return 0;
}