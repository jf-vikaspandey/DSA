// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770

#include <stdio.h>
#include <stack>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int maxDepth(string &st)
{

    stack<char> ch;
    int maxDepth = 0;
    int currentDepth = 0;
    for (int i = 0; i < st.length(); i++)
    {
        if (st[i] == '(')
        {
            currentDepth += 1;
            maxDepth = max(currentDepth, maxDepth);
        }
        else if (st[i] == ')')
        {
            currentDepth -= 1;
        }
    }
    cout << maxDepth;
    return 0;
    ;
}
int main()
{

    string s = "(1)+((2))+(((3)))";

    int n = maxDepth(s);
}