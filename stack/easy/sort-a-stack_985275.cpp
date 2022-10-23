// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275

#include <stdio.h>
#include <stack>
#include <string>
#include <bits/stdc++.h>
using namespace std;
void solveSort(stack<int> &st, int num)
{
    if (st.empty() || st.top() <= num)
    {
        st.push(num);
        return;
    }
    int res = st.top();
    st.pop();
    solveSort(st, num);
    st.push(res);
}
void sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int res = st.top();
    st.pop();
    sortStack(st);
    solveSort(st, res);
}
int main()
{
    int size = 4;
    stack<int> st;
    st.push(1);
    st.push(31);
    st.push(4);
    st.push(5);

  
    sortStack(st);

    while (!st.empty())
    {
        cout << st.top() << "\t";
        st.pop();
    }
    return 0;
}