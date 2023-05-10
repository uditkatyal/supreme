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

Node *mergeLL(Node *&head1, Node *&head2)
{

    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            Node *newNode = new Node(head1->data);
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
            head1 = head1->next;
        }
        else
        {
            Node *newNode = new Node(head2->data);
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
            head2 = head2->next;
        }
    }

    while (head1 != NULL)
    {
        Node *newNode = new Node(head1->data);
        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        Node *newNode = new Node(head2->data);
        ansTail->next = newNode;
        ansTail = newNode;
        head2 = head2->next;
    }
    return ansHead;
}

int main()
{
    Node *first = new Node(2);
    Node *second = new Node(5);

    Node *fourth = new Node(1);
    Node *fifth = new Node(7);
    // Node *sixth = new Node(9);

    first->next = second;
    second->next = NULL;

    fourth->next = fifth;
    fifth->next = NULL;
    // sixth->next = NULL;

    print(first);
    cout << endl;
    print(fourth);
    cout << endl;

    Node *ansHead = mergeLL(first, fourth);
    print(ansHead);
    cout << endl;
    return 0;
}