#ifndef UNIT14EXER9_DEFINITION_H
#define UNIT14EXER9_DEFINITION_H

#endif //UNIT14EXER9_DEFINITION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LEN 14
#define SIZE 12
#define MAX 256

struct plane{
    int number;
    int book;
    bool confirm;
    char f_name[LEN];
    char l_name[LEN];
};

void menu(int num);
char get_a(void);
char * s_gets(char *st,int n);
int choose_a(int num,struct plane arr[num]);
void choose_b(int num,struct plane arr[num]);
void choose_c(int num,struct plane arr[num]);
void choose_d(int num,struct plane (*arr)[num]);
void choose_e(int num,struct plane (*arr)[num]);
void choose_g(int num,struct plane (*arr)[num]);
