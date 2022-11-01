// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770

#include <stdio.h>
#include <stack>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<int> maxDepth(string &vpsSeq, int n)
{
    vector<int> result;
    int currentDepth = 0;

    // Processing the depth of every parentheses and putting odd depth parenthesis in 'X' and even depth parenthesis in 'Y'.
    for (char &ch : vpsSeq)
    {
        // Going deeper in the string. So, increment 'currentDepth'.
        if (ch == '(')
        {
            currentDepth++;
            result.push_back(currentDepth % 2);
        }
        // Coming out of the depth. So, decrement 'currentDepth'.
        else
        {
            result.push_back(currentDepth % 2);
            currentDepth--;
        }
    }
    
    return result;
    
}
int main()
{

    string s = "(())";
    
    vector n = maxDepth(s,4);
    
    for(int i=0;i<n.size();i++){
        cout<<n[i];
    }
}