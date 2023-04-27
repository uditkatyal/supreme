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

// method 1 (with data replacement)

// method 2 (playing with pointers) this is how we should solve LL problems

Node *sort012(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return NULL;
    }
    // create dummy nodes
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    // attaching nodes with corresponding values

    Node *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr;
        curr = curr->next;
        temp->next = NULL;
        if (temp->data == 0)
        {
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (temp->data == 1)
        {
            oneTail->next = temp;
            oneTail = temp;
        }
        else if (temp->data == 2)
        {
            twoTail->next = temp;
            twoTail = temp;
        }
    }

    // deleting dummy nodes

    Node *temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    // join
    if (oneHead != NULL)
    {
        zeroTail->next = oneHead;
        oneTail->next = twoHead;
    }
    else
    {
        // if (twoHead != NULL)
        // {
        zeroTail->next = twoHead;
        // }
    }

    temp = zeroHead;
    zeroHead = zeroHead->next;

    temp->next = NULL;
    delete temp;

    // return head

    return zeroHead;
}

int main()
{

    Node *first = new Node(1);
    Node *second = new Node(0);
    Node *third = new Node(2);
    Node *fourth = new Node(0);
    Node *fifth = new Node(1);
    Node *sixth = new Node(2);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    print(first);
    cout << endl;

    // Node *null = NULL;
    first = sort012(first);
    print(first);
    return 0;
}