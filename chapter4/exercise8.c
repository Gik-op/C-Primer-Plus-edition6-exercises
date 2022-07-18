#include <stdio.h>
#define TRAFER 235.24

int main() {
    double leng,oil,m_g,l_k;
    printf("Input the length(mile) and the oil(gallon) you spent:\n");
    scanf("%lf %lf",&leng,&oil);
    m_g = leng/oil;
    l_k = TRAFER/m_g;
    printf("In American, %.1fmile/gallon.\nIn Europe, %.1fL/100km.\n",m_g,l_k);
    return 0;
}
