#include"stack.hpp"

Stack::Stack()
{
    size = STACK_SIZE;
    ptr  = 0;

    arr  = (int*)malloc(sizeof(int)*size);
    if(!arr){printf("Memmory Error\n"); exit(1);}
}


Stack::~Stack()
{
     free(arr);
     size = 0;
}


void Stack::push(int new_el)
{
    if(size == ptr+1)
    {
        size = 2*size;
        arr  = (int*)realloc(arr, size*sizeof(int));

        if(!arr){printf("Memmory Error\n"); exit(1);}
    }

    arr[ptr++] = new_el;
}


int Stack::get()
{
    return arr[ptr];
}


int Stack::pop()
{
    if(ptr)
        return arr[--ptr];
    else
    {
        printf("Empty Stack function pop() return -1\n");
        return -1;
    }
}


bool Stack::is_empty()
{
    return !ptr;
}


int Stack::get_size()
{
    return ptr+1;
}


void Stack::do_empty()
{
    ptr = 0;
}


