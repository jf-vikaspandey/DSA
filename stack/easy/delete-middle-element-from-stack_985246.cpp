#include <stdio.h>
#include <iostream>

#include <stack>
using namespace std;

void removeMiddel(stack<int> &st, int N, int current)
{
 if (current == 0)
    {
        st.pop();
    }
    else
    {
        int val = st.top();
        st.pop();
        removeMiddel(st, N, current - 1);
        st.push(val);
    }
}
void deleteMiddle(stack<int> &st, int N)
{

    removeMiddel(st, N, (N / 2));

    // Write your code here
}
int main()
{

    int size = 4;
    stack<int> st;
    st.push(7);
    st.push(2);
    st.push(4);
    st.push(3);
    st.push(1);

    deleteMiddle(st, size);

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
        /* code */
    }

    return 0;
}
