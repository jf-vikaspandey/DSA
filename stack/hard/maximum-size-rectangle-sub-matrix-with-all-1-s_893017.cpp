//
// https://www.codingninjas.com/codestudio/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017

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
        int b = next[i] - prev[i] - 1;

        area = max((l * b), area);
    }
    return area;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &vt, int n, int m)
{

    int status = largestRectangle(vt[0]);
    // Write your code here.
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vt[i][j] != 0)
            {
                vt[i][j]= vt[i][j] + vt[i - 1][j];
            }else{
                 vt[i][j]=0;
            }
        }

        int space = largestRectangle(vt[i]);

        status = max(status, space);
    }
    return status;
}

int main()
{
    vector<vector<int>> vt(2, vector<int>(3));

    vt[0][0] = 1;
    vt[0][1] = 1;
    vt[1][0] = 1;
    vt[1][1] = 1;
    int size = maximalAreaOfSubMatrixOfAll1(vt, 2, 2);

    return 0;
}