#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
#include <iostream>
#include <queue>
class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    MyStack()
    {
    }

    void push(int x)
    {

        q2.push(x);

         while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> tmp = q1;
        q1 = q2;
        q2 = tmp;
    }

    int pop()
    {
        int a = q1.front();
        ;

        q1.pop();
        return a;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

// Driver code
int main()
{
    MyStack* obj = new MyStack();
 obj->push(1);
 obj->push(2);
 obj->push(3);
  cout<< obj->pop();
  cout<< obj->pop();
  cout<< obj->pop();
  
 // cout<< obj->top();
    return 0;
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */