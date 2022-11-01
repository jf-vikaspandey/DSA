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
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {

            count++;
            if (count > 1)
            {
                s1 += '(';
            }
        }
        else
        {
            if (count > 1)
            {
                s1 += ')';
            }
            count--;
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