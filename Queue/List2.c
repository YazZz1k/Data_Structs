#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define  x 20

#include"List2.h"


Vibor* Vibor_Create(int st, int end, int dl)
{
    Vibor* ret = (Vibor*)malloc(sizeof(Vibor));

    assert(ret!=NULL);

    ret->st  = st;
    ret->end = end;
    ret->dl  = dl;

    return ret;
}


Vibor* Vibor_Copy(Vibor *cop)
{
    assert(cop != NULL);

    Vibor *ret = (Vibor*)malloc(sizeof(Vibor));

    assert(ret);

    ret->st  = cop->st;
    ret->end = cop->end;
    ret->dl  = cop->dl;

    return ret;
}


List* List_Create(Vibor *val)
{
    assert(val);

    List * ret =(List*)malloc(sizeof(List));

    assert(ret);

    ret->val    = Vibor_Copy(val);
    ret->next   = NULL;
    ret->before = NULL;

    return ret;
}


Queue* Queue_Create()
{
    Queue* ret = (Queue*)malloc(sizeof(Queue));

    assert(ret);

    ret->empty = 1;
    ret->front = NULL;
    ret->back  = NULL;

    return ret;
}


void push(Vibor* data, Queue* que)
{
    assert(que);
    assert(data);
    assert(!(!que->front && que->back));
    assert(!(que->front && !que->back));

    if(que->empty)
    {
        que->front = malloc(sizeof(List));
        que->back  = que->front;
        que->front->val = data;

        que->empty = 0;
    }
    else
    {
        List *new_el      = List_Create(data);
        que->back->before = new_el;
        new_el->next      = que->back;
        que->back         = new_el;
    }
}


Vibor* get(Queue * que)
{
    assert(que);

    if(que->empty)
    {
        printf("error in function get:: Пустая очередь\n");
        assert(0);
    }
    else
        return que->front->val;
}


void pop(Queue * que)
{
    assert(que);

    if(que->empty)
    {
        printf("error in function pop::Пустая очередь\n");
        assert(0);
    }
    else
    {
        if(que->front == que->back)
        {
            que->empty = 1;

            free(que->front->val);
            free(que->front);
            que->front = NULL;
            que->back  = NULL;
        }
        else
        {
            assert(que->front->before);

            free(que->front->val);

            List* tmp = que->front;

            que->front = que->front->before;
            que->front->next = NULL;

            free(tmp);
        }
    }
}


void List_Delete(List* list)
{
    if(list)
    {
        free(list->val);

        List_Delete(list->next);

        free(list);
    }
}


void Queue_Delete(Queue* que)
{
    List_Delete(que->back);
    free(que);
}


int main()
{
    Queue* que = Queue_Create();
    Vibor* vib = Vibor_Create(1,2,3);

    for(int i = 0; i<1000; i++)
    {
        vib->st = i;
        push(vib, que);
    }

    free(vib);

    for(int i = 0; i<100; i++)
    {
        printf("%d\n", get(que)->st);
        pop(que);
    }

    Queue_Delete(que);
}
