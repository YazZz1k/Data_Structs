#include"stack.hpp"

int main()
{
    Stack st;
    for(int i=0; i<100000; i++)
        st.push(i);

    for(int i=0; i<100002; i++)
        printf("%d %d\n", st.get(), st.pop());




    return 0;

}
