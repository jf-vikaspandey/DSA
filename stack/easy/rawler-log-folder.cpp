#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int minOperations(vector<string> &logs)
{

    int n = 0;

    for (int i = 0; i < logs.size(); i++)
    {

        if (logs[i] == "../" && n > 0)
        {
            n--;
        }
        else if (logs[i] == "./")
        {
        }
        else
        {

            if (logs[i] != "../")
            {
                n++;
                
            }
        }
        // cout << n << logs[i] <<"vi---"<< endl;
    }

    return n;
}
int main()
{

    vector<string> logs;

    logs.push_back("d1/");
    logs.push_back("../");
    logs.push_back("../");

    int n = minOperations(logs);

    cout << n;
    return 0;
}