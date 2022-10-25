// https://www.codingninjas.com/codestudio/problems/largest-rectangle-in-a-histogram_1058184
#include <stdio.h>
#include <stack>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<int> getnextMinimum(vector<int> &heights)
{
    stack<int> st;
    st.push(-1);
    vector<int> next(heights.size());
    for (int i = heights.size() - 1; i >= 0; i--)
    {

        while (st.top() != -1 && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        next[i] = st.top();
        st.push(i);
    }
    return next;
}
vector<int> getprevMinimum(vector<int> &heights)
{
    stack<int> st;
    st.push(-1);

    vector<int> next(heights.size());
    for (int i = 0; i < heights.size(); i++)
    {
        while (st.top() != -1 && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        next[i] = st.top();
        st.push(i);
    }
    return next;
}
int largestRectangle(vector<int> &heights)
{
    // Write your code here.

    vector<int> next = getnextMinimum(heights);
    vector<int> prev = getprevMinimum(heights);

    int area = 0;

    int n = heights.size();
    for (int i = 0; i < heights.size(); i++)
    {

        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = (next[i]-1 -( prev[i]-1));

        area = max((l * b), area);
    }
    return area;
}

int main()
{
    vector<int> vt;
    vt.push_back(1);
    vt.push_back(2);
    vt.push_back(1);
    vt.push_back(0);
    vt.push_back(1);
    vt.push_back(1);
    vt.push_back(0);
    vt.push_back(0);
    vt.push_back(2);
    vt.push_back(2);

    int size = largestRectangle(vt);
    cout << "\n"
         << size;
    return 0;
}