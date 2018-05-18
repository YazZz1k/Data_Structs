#include"set.h"

int f(const void* a,const void* b)
{
   // printf("Hello, i am cmp-function!\n");
    int a_1 = **(int**)a;
    int b_1 = **(int**)b;


    if(a_1==b_1)
    {
    //    printf("%d = %d\n", a_1, b_1);
        return 0;
    }

    else if(a_1<b_1)
    {
    //    printf("%d < %d\n", a_1, b_1);
        return 1;
    }

    else if(a_1>b_1)
    {
     //   printf("%d > %d\n", a_1, b_1);
        return -1;
    }
    else
    {
        printf("HUI\n");
    }
}



int main()
{
    Set* set = Create_Set(f, sizeof(int));

    int a = 0;
    int i=0;


    for(i=0; i<10; i++)
    {
        a = a+12;
        Add(&a, set);
    }
    for(i=0; i<1000; i++)
    {
        a = a - 14;
        Remove(&a, set);
    }

    print_int_set(set);
    printf("%d\n", *(int*)get(400, set));
    Distruct_Set(set);
    return 0;
}
