
#include <stdio.h>
#include <stack>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string makeGood(string s)
{

    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        if (!st.empty() && (((st.top() == s[i] - 32)) || ((st.top() == s[i] + 32))))
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    string s1 = "";
    while (!st.empty())
    {

        s1 = st.top() + s1;
        st.pop();
    }
 
    return s1;
}

int main()
{

    string s = "Ee";
    s = makeGood(s);
    return 0;
}
