#include"stack.hpp"

int main()
{
    int arr[6];
    for(int i=0; i<6; i++)
        arr[i]=i;
    Stack s(arr, 6);

    int len = s.get_size();
    for(int i=0; i<len; i++)
        printf("%d\n", s.pop());

    return 0;
}
