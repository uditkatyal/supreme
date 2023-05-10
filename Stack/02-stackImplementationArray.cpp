// stack implementation using array
#include <iostream>
using namespace std;

class Stack
{

public:
    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = data;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
    }
    int getTop()
    {
        if (top == -1)
        {
            cout << "There is no element in stack" << endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty()
    {
        return (top == -1) ? true : false;
    }
    int getSize()
    {
        // number of elements in stack
        return top + 1;
    }
};

int main()
{
    Stack s(10);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    while (!s.isEmpty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}