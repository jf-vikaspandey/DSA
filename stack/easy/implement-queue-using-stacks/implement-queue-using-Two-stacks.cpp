#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    stack<int> input;
    stack<int> output;

    MyQueue()
    {
    }

    void push(int x)
    {

        input.push(x);
    }

    int pop()
    {

        if (output.empty() && input.empty())
        {
            return 0;
        }

        if (output.empty())
        {
            moveInput();
        }

        int a = output.top();

        output.pop();
        return a;
    }

    void moveInput()
    {
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
    }
    int peek()
    {
        if (output.empty() && input.empty())
        {
            return 0;
        }
        if (output.empty())
        {
            moveInput();
        }

        return output.top();
    }

    bool empty()
    {

        if (output.empty() && input.empty())
        {
            return true;
        }

         if (output.empty())
        {
            moveInput();
        }
        return output.empty();
    }
};

int main()
{

    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);

    cout << obj->pop();
    cout << obj->pop();
    obj->push(5);
    cout << obj->pop();
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
