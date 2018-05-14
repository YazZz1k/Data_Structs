#include"set.h"


Set* Create_Set(int(*compare)(const void* el_1,const void* el_2), size_t _sizeof)
{
    int i=0;
    assert(compare);

    Set* created_set = (Set*)calloc(1,sizeof(Set));

    if(!created_set) Error(MEMORY_0);

    created_set->arr = calloc(DEFAULT_SET_SIZE,sizeof(void*));

    if(!created_set->arr) Error(MEMORY_0);


    for(i=0; i<DEFAULT_SET_SIZE; i++)
    {
        created_set->arr[i] = malloc(sizeof(void));
        assert(created_set->arr[i]);
    }

    created_set->size    = DEFAULT_SET_SIZE;
    created_set->len     = 0;
    created_set->cmp     = compare;
    created_set->_sizeof = _sizeof;

    return created_set;
}


int Add(void* Data, Set* set)
{
    Set_Assert(set);
    assert(Data);
    void *destptr = NULL;

    if(_search(Data, set)>=0)
        return 0;
    else
    {
        if(set->len >= set->size)
        {
            int i=set->size;

            set->size = 2*set->size;
            set->arr = realloc(set->arr, set->size*sizeof(void*));

            if(!set->arr) Error(MEMORY_1);

            for(i; i<set->size; i++)
            {
                set->arr[i] = malloc(sizeof(void));
                if(!set->arr[i]) Error(MEMORY_1);
            }
        }

        assert(set->len<set->size);

        destptr = set->arr[set->len++];

        memmove(destptr, Data, set->_sizeof);
        assert(destptr);

        _sort(set);
        return 1;
    }
}


void _sort(Set* set)
{
    Set_Assert(set);
    qsort(set->arr, set->len, sizeof(void*), set->cmp);
}


int _search(void* Data, Set* set)
{
    assert(Data);
    Set_Assert(set);

    int (*cmp)(const void* el_1,const void* el_2);
    int tmp;
    cmp = set->cmp;

    int i=0;

    for(i=0; i<set->len; i++)
    {
        if(!cmp(&Data, &set->arr[i]))
            return i;
    }

    return -1;
}


void Distruct_Set(Set* set)
{
    Set_Assert(set);
    int size = set->size,
        i = 0;

    for(i=0; i<size; i++)
    {
        assert(set->arr[i]);
        free(set->arr[i]);
    }

    free(set->arr);
    free(set);
}


size_t get_len(Set* set)
{
    Set_Assert(set);

    return set->len;
}


int Remove(void* Data, Set* set)
{
    Set_Assert(set);

    int index = _search(Data, set);

    if(index>=0)
    {
        assert(index<set->len);
        void* tmp_ptr = set->arr[index];
        while(index<set->len-1)
        {
           set->arr[index] = set->arr[index+1];
           index++;
        }
        set->arr[set->len-1] = tmp_ptr;
        set->len--;
        return 1;
    }
    else
        return 0;
}


int Find(void* Data, Set* set)
{
    Set_Assert(set);

    return _search(Data, set);
}


void* get(int index, Set* set)
{
    if(index>=set->len) Error(OUT_OF_ARR);

    void* ret_ptr = malloc(sizeof(void));

    memmove(ret_ptr, set->arr[index], set->_sizeof);
    return ret_ptr;
}


void Set_Assert(Set* set)
{
    int i=0;
    assert(set);
    assert(set->arr);

    for(i=0; i<set->size; i++)
        assert(set->arr[i]);
}


void print_int_set(Set* set)
{
    int i=0;
    int len = set->len;
    printf("len = %d\n", len);

    for(i=0; i<len; i++)
        printf("%d ", *(int*)set->arr[i]);

    printf("\n");
}



void Error(Er_Enum Err)
{
    switch(Err)
    {
        case MEMORY_0:   fprintf(stderr, "Error\n"); break;
        case MEMORY_1:   fprintf(stderr, "Error\n"); break;
        case OUT_OF_ARR: fprintf(stderr, "Error\n"); break;
    }

    exit(Err);
}

