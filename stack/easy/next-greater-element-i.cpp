#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    stack<int> st;
    int num1Size = nums1.size();
    int num2Size = nums2.size();
    st.push(-1);
    unordered_map<int, int> umap;

    for (int i = num2Size - 1; i >= 0; i--)
    {umap[nums2[i]] = -1;

        while (!st.empty())
        {
            if (st.top() > nums2[i])
            {

                umap[nums2[i]] = st.top();

                break;
            }
            else
            {
               
                st.pop();
            }
        }

        st.push(nums2[i]);
    }

    for (int i = 0; i < num1Size; i++)
    {
        res.push_back(umap[nums1[i]]);
    }

    return res;
}
int main()
{
   vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(3);
    nums1.push_back(5);
    nums1.push_back(2);
    nums1.push_back(4);

    vector<int> nums2;
    nums2.push_back(6);
    nums2.push_back(5);
    nums2.push_back(4);
    nums2.push_back(3);
    nums2.push_back(2);
    nums2.push_back(1);
    nums2.push_back(7);

    vector<int> res = nextGreaterElement(nums1, nums2);

for(int i=0;i<res.size();i++){
    cout<<res[i]<<endl;
}
    return 0;
}