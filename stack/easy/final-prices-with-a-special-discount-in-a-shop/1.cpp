// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770

#include <stdio.h>
#include <stack>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<int> finalPrices(vector<int> &prices)
{
    int i = 0;
    int j = 1;
    int n = prices.size();

    vector<int> priceList(n);

    while (i < n)
    {

        if (j < n)
        {

          
            if (prices[j] <= prices[i])
            {
                priceList[i] = prices[i] - prices[j];
                i++;
                j = i;
            }

            j++;
        }
        else
        {
            priceList[i] = prices[i];
            i++;
            j = i + 1;
        }
    }

    return priceList;
}

int main()
{

    vector<int> n = {8, 4, 6, 2, 3};

    n = finalPrices(n);
    for (int i = 0; i < n.size(); i++)
    {
        cout << n[i];
    }
}