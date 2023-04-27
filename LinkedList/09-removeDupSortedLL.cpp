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

Node *removeDup(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }
    // two or more ele exits

    Node *temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        if (temp->data != temp->next->data)
        {
            temp = temp->next;
        }
        else
        {
            Node *ptr = temp->next;
            temp->next = temp->next->next;
            ptr->next = NULL;
            delete ptr;
        }
    }
    return head;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(10);
    Node *third = new Node(20);
    Node *fourth = new Node(20);
    Node *fifth = new Node(30);
    Node *sixth = new Node(40);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    print(first);
    cout << endl;

    first = removeDup(first);

    print(first);

    return 0;
}