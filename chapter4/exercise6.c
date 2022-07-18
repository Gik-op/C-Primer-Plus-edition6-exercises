#include <stdio.h>
#include <string.h>

int main()
{
    char name1[20],name2[20];
    int len1,len2;
    printf("Input your first name:");
    scanf("%s",name1);
    printf("Input your family name:");
    scanf("%s",name2);
    len1 = strlen(name1);
    len2 = strlen(name2);//这一步计算无误
    printf("%s %s\n%*d %*d\n",name1,name2,len1,len1,len2,len2);
    printf("%s %s\n%-*d %-*d\n",name1,name2,len1,len1,len2,len2);
    return 0;
}
