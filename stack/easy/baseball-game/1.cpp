// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770

#include <stdio.h>
#include <stack>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int calPoints(vector<string> &operations)
{

    stack<int> stt;
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i] == "C")
        {
            if (!stt.empty())
            {
                stt.pop();
            }
        }
        else if (operations[i] == "D")
        {
            if (!stt.empty())
            {
                int SNum = stt.top();
                stt.push(SNum * 2);
            }
        }
        else if (operations[i] == "+")
        {
            if (stt.size() > 1)
            {
                int first = stt.top();
                stt.pop();
                int second = stt.top();
                stt.push(first);
                stt.push(first + second);
            }
        }
        else
        {
            stt.push(stoi(operations[i]));
        }
    }

    int si = 0;

    while (!stt.empty())
    {

        int i = stt.top();
        stt.pop();

        si += i;
       
    }
    return s1;
}

int main()
{

    vector<string> n = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    int s = calPoints(n);

    return 0;
}