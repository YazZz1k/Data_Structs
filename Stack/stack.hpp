#ifndef __Stack__HPP__
#define __Stack__HPP__

#define STACK_SIZE 128

#include<stdlib.h>
#include<stdio.h>

class Stack
{
    private:
        int*   arr;
        int    ptr;
        size_t size;
    public:
        Stack();
        ~Stack();
        void push(int new_el);
        int  pop();
        int  get();
        bool is_empty();
        int  get_size();
        void do_empty();
};

#endif

