#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node *&head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
// Recursively
Node *reverseListRec(Node *&prev, Node *&curr)
{
    // base case
    if (curr == NULL)
    {
        return prev;
    }
    // ek case hum krnege solve

    Node *forward = curr->next;
    curr->next = prev;

    // baaki recursion sambhal lega

    return reverseListRec(curr, forward);
}
// iteratively
Node *reverseWithLoop(Node *&prev, Node *&curr)
{

    while (curr != NULL)
    {
        Node *forward = curr->next;
        curr->next = prev;

        prev = curr;
        curr = forward;
    }
    return prev;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    print(first);
    cout << endl;

    Node *prev = NULL;

    // first = reverseListRec(prev, first);
    first = reverseWithLoop(prev, first);

    print(first);
    cout << endl;

    return 0;
}