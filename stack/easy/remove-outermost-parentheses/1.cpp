// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770

#include <stdio.h>
#include <stack>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s)
{

    stack<char> ch;

    string s1 = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            if (ch.size() > 0)
            {
                s1 += '(';
            }

            ch.push('(');
        }
        else
        {
            if (ch.size() > 1)
            {
                s1 += ')';
            }
            ch.pop();
        }
    }

    return s1;
}

int main()
{

    string s = "(()())(())(()(()))";

    s = removeOuterParentheses(s);
    cout << s;
}