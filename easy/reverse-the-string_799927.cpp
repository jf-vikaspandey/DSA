//https://www.codingninjas.com/codestudio/problems/reverse-the-string_799927

#include <stdio.h>
#include <stack>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string reverseString(string str)
{

    string finalStr = "";
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
    }

    while(!st.empty())
    {
        char cha = st.top();
        finalStr.push_back(cha);
         st.pop();
    }

    // Write your code here.

    return finalStr;
}

int main()
{

    string s = "VikasPandey";
    s = reverseString(s);

    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i];
    }

    return 0;
}