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

Node *reverseList(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = curr;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node *addList(Node *&first, Node *&second)
{

    int ans = 0;
    int carry;
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (first != NULL && second != NULL)
    {
        int digit = first->data + second->data + carry;
        ans = digit % 10;
        carry = digit / 10;

        Node *newNode = new Node(ans);
        if (ansHead == NULL)
        {
            ansHead = newNode;
            ansTail = newNode;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }

        first = first->next;
        second = second->next;
    }

    while (first != NULL)
    {
        int digit = first->data + carry;
        ans = digit % 10;
        carry = digit / 10;

        Node *newNode = new Node(ans);
        ansTail->next = newNode;
        ansTail = newNode;
        first = first->next;
    }

    while (second != NULL)
    {
        int digit = second->data + carry;
        ans = digit % 10;
        carry = digit / 10;

        Node *newNode = new Node(ans);
        ansTail->next = newNode;
        ansTail = newNode;
        second = second->next;
    }

    if (carry)
    {
        int digit = carry % 10;
        carry = carry / 10;

        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }

    return ansHead;
}

int main()
{
    Node *first = new Node(9);
    Node *second = new Node(9);

    Node *fourth = new Node(9);
    Node *fifth = new Node(9);
    // Node *sixth = new Node(9);

    first->next = second;
    second->next = NULL;

    fourth->next = fifth;
    fifth->next = NULL;
    // sixth->next = NULL;

    // print(first);
    cout << endl;

    first = reverseList(first);
    fourth = reverseList(fourth);

    Node *ansHead = addList(first, fourth);

    ansHead = reverseList(ansHead);
    print(ansHead);

    return 0;
}