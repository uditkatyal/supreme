// implementing two stacks in one array from start and end
#include <iostream>
#include <string.h>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        arr = new int[size]();
        this->size = size;
        top1 = -1;
        top2 = size;
    }
    void push1(int data)
    {

        if (top2 - top1 == 1)
        {
            cout << "Stack 1 Overflow" << endl;
            return;
        }
        arr[++top1] = data;
    }
    void push2(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "stack 2 overflow" << endl;
            return;
        }
        arr[--top2] = data;
    }
    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack 1 underflow" << endl;
            return;
        }
        // this is done just to show it is removed , although not required if not printing
        arr[top1] = 0;
        top1--;
    };
    void pop2()
    {
        if (top2 == size)
        {
            cout << "Stack 2 underflow" << endl;
            return;
        }
        // this is done just to show it is removed , although not required if not printing
        arr[top2] = 0;
        top2++;
    };

    // never write such print func this is done just to demonstarte the values
    void print()
    {
        cout << endl;
        cout << "top1 " << top1 << " " << endl;
        cout << "top2 " << top2 << " " << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s(10);

    s.print();
    s.push1(10);
    s.print();
    s.push2(100);
    s.print();
    s.push1(20);
    s.print();
    s.push2(90);
    s.print();

    s.pop1();
    s.print();

    s.push1(110);
    s.print();
    s.push1(120);
    s.print();
    s.push1(130);
    s.print();
    s.push1(140);
    s.print();
    s.push1(150);
    s.print();
    s.push1(160);
    s.print();
    s.push1(170);
    s.print();

    s.pop1();
    s.print();
    s.push2(280);
    s.print();

    return 0;
}