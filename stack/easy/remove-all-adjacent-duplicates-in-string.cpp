#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
string removeDuplicates(string s)
{

    stack<char> st;
    st.push(s[0]);
    int count = 1;
    for (int i = 1; i < s.length(); i++)
    {

        if (!st.empty() && st.top() == s[i])
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
    string s = "abbaca";
    string s1 = removeDuplicates(s);
    cout << s1;
    return 0;
}