#include"list.hpp"

void print_list(List<int> list)
{
    for(int i=0; i<list.size(); i++)
    {
        printf("%d\n", list.front());
        list.pop();
    }
}

int main()
{
    List<int> li_1, li_2;
    for(int i = 0; i<10; i++)
        li_1.push(i);

    for(int i = 0; i<10; i++)
        li_2.push(i);

    List<int> n_li = li_1+li_2;

    print_list(n_li);

    for(int i=0; i<n_li.size(); i++)
        printf("element %d: %d\n", i, n_li[i]);
}
