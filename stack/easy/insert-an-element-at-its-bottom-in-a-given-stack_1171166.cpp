// https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?leftPanelTab=1

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

stack<int> pushAtBottom(stack<int> &myStack, int x)
{

    solve(myStack, x);
    return myStack;
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
    st = pushAtBottom(st, 10);

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}