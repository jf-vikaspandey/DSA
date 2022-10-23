#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string str)
{
    bool status = true;
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '[' || str[i] == '(' || str[i] == '{')
        {
            st.push(str[i]);
        }
        else
        {
            if (!st.empty())
            {
                char ch = st.top();
                if (str[i] == ')' && ch != '(')
                {
                    status = false;
                }
                else if (str[i] == ']' && ch != '[')
                {
                    status = false;
                }
                else if (str[i] == '}' && ch != '{')
                {
                    status = false;
                }

                st.pop();
            }else{
                 status = false;
            }
        }
    }

    if (!st.empty())
    {
        status = false;
    }

    return status;
}

void start(string str)
{

    bool status = isValidParenthesis(str);

    if (status == true)
    {
        cout << "Balanced\n";
    }
    else if (status == false)
    {
        cout << "Not Balanced\n";
    }
}
int main()
{
  //  start("[]");
    start("())");
   // start("{[(");

    return 0;
}