// https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?leftPanelTab=1
#include <stdio.h>
#include <stack>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &myStack, int x)
{

    if (myStack.empty())
    {
        myStack.push(x);
    }
    else
    {
        int val = myStack.top();
        myStack.pop();
        solve(myStack, x);
        myStack.push(val);
    }
}

void pushAtBottom(stack<int> &myStack, int x)
{

    solve(myStack, x);
}

void reserve(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int val = st.top();
    st.pop();
    reserve(st);
    pushAtBottom(st, val);
}

int main()
{
    int size = 4;
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    reserve(st);

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}