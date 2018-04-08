#ifndef __LIST__2__
#define __LIST__2__

#include<assert.h>
#include<stdio.h>

typedef struct Vibor
{
    int st, end, dl;
}Vibor;


typedef struct List
{
    struct List *next,
                *before;
    Vibor *val;
}List;


typedef struct Queue
{
    List *front,
         *back;

    int empty;  //1-empty 0-don't empty
}Queue;


Vibor* Vibor_Create(int st, int end, int dl);
Vibor* Vibor_Copy(Vibor *cop);
List* List_Create(Vibor *val);
Queue* Queue_Create();
void push(Vibor* data, Queue* que);
Vibor* get(Queue * que);
void pop(Queue * que);
void List_Delete(List* list);
void Queue_Delete(Queue* que);

#endif
