#ifndef __SET__
#define __SET__

#include<stdio.h>

#define DEFAULT_SET_SIZE

typedef int Data;

typedef struct Set
{
    Data* arr;
}Set;

int compare(Data el_1, Data el_2)
{
    return 0;
}

void Set_Compare_Function(int(*compare)(Data* el_1, Data* el_2));
Set* Create_Set();
void push(Data el);
Data get(int index);
void delete_el(Data a);


#endif
