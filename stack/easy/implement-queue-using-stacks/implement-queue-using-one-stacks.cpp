#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    stack<int> input;

    MyQueue()
    {
    }

    void push(int x)
    {

        input.push(x);
    }

    int pop()
    {

        if (input.empty())
        {
            return 0;
        }

        int top = input.top();

        input.pop();
        if (input.empty())
        {
            return top;
        }

        int item = pop();

        input.push(top);

        return item;
    }

    void addInLast(int a)
    {
        if (input.empty())
        {
            input.push(a);
            return;
        }

        int last = input.top();
        input.pop();

        addInLast(a);
        input.push(last);
    }
    int peek()
    {

        int a = pop();

        addInLast(a);
        return a;
    }

    bool empty()
    {

        return input.empty();
    }
};

int main()
{

    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << obj->peek();
    cout << obj->pop();
      cout << obj->peek();
    cout << obj->empty();
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
