//https://www.codingninjas.com/codestudio/problems/redundant-brackets_97547

#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool findRedundantBrackets(string &str)
{
    bool status = false;
    stack<char> st;
    for (size_t i = 0; i < str.length(); i++)
    {

        if (str[i] == '(' || str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')')
        {
            int count = 0;

            while (!st.empty() && st.top() != '(')
            {
                char ch = st.top();
                if (ch == '*' || ch == '+' || ch == '-' || ch == '/')
                {

                    count = 1;
                }
                st.pop();
            }

            if (count == 0)
            {
                status = true;
            }
            st.pop();
        }
    }

   
    return status;
}

int main()
{
    string str = "(a+c*b)+(a+c))";
    bool status = findRedundantBrackets(str);
    cout << status << endl;
    return 0;
}