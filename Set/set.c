#include<stdio.h>

typedef int Data;

int compare(Data a, Data b)
{
    return 1;
}

void f(int (*func)(Data, Data))
{
    printf("%d\n", func(1,2));
}


int main()
{
    f(compare);
}
