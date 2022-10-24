// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770

#include <stdio.h>
#include <stack>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str)
{

    if (str.length() % 2 == 1)
    {
        return -1;
    }
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
        {
            st.push(str[i]);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }
    }

    int a = 0, b = 0;
    while (!st.empty())
    {
        if (st.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
        st.pop();
    }

    return ((a + 1) / 2 + (b + 1) / 2);
}

int main()
{
    int count = 0;

    count = findMinimumCost("{{{}");
    cout << count << endl;

    count = findMinimumCost("{{}{}}");
    cout << count << endl;

    count = findMinimumCost("{}}{}}");
    cout << count << endl;

    count = findMinimumCost("{{{{");
    cout << count << endl;

    count = findMinimumCost("{{{}}");
    cout << count << endl;

    return 0;
}