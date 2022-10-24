// https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581

#include <stdio.h>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;

    st.push(-1);
    vector <int> result(n);
    for (int i = n - 1; i >= 0; i--)
    {

        while (st.top() >= arr[i])
        {
            st.pop();
        }
        result[i]=st.top();
        st.push(arr[i]);
    }

    return result;
}

int main()
{

    vector<int> s = {2, 1, 4, 3};
    vector s1 = nextSmallerElement(s, s.size());

    for (int i = 0; i < s1.size(); i++)
    {
          cout << s1[i] << endl;
    }

    return 0;
}