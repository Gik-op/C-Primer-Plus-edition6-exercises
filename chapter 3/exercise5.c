#include <stdio.h>

int main() {
    double year_time = 3.156e7;
    double age_s,age;
    printf("please enter you age(year):");
    scanf("%lf",&age);
    printf("%f\n",age);
    age_s = year_time*age;
    printf("Your age has %f seconds.\n",age_s);
    return 0;
}
