// https://www.geeksforgeeks.org/implement-two-stacks-in-an-array
// https://www.codingninjas.com/codestudio/problems/two-stacks_983634
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class TwoStack
{

public:
    int top1;
    int top2;
    int size;
    int *arr;
    TwoStack(int size)
    {
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
        arr = new int[size];
    }

    void push1(int element)
    {

        if (top2 - top1 > 1)
        {
            this->top1++;
            this->arr[top1] = element;
        }
       
    }

    int pop1()
    {

        if (this->top1 == -1)
        {
            return -1;
        }
        else
        {
            int res = this->arr[this->top1];
            this->top1--;
            return res;
        }
    }

    void push2(int element)
    {
        if (top2 - top1 > 1)
        {
            this->top2--;
            this->arr[top2] = element;
        }


    }

    int pop2()
    {
        if (this->top2 == (size))
        {
            return -1;
        }
        else
        {
          
            int res = this->arr[this->top2];
            this->top2++;
            return res;
        }
    }
};

main()
{
    TwoStack twoStack(3);
    twoStack.push1(3);
      twoStack.push2(4);
     twoStack.push1(5);
   
   
    cout << twoStack.pop1() << endl;
    cout << twoStack.pop2() << endl;
}
