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
int findLength(Node *&head)
{
    Node *temp = head;
    int len = 0;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// slow-fast pointer

Node *middle(Node *&head)
{
    //
    if (head == NULL)
    {
        cout << "empty list" << endl;
        return head;
    }
    Node *slow = head;
    // 10 20 30 40 50 60
    // and we require 30 as the mid not 40 then start fast from head->next
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// BRUTE APPRAOCH

Node *middleOfLinkedList(Node *&head)
{

    // if LL is empty
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }
    int len = findLength(head);
    Node *temp = head;
    int counter;
    if (len % 2 == 0)
    {
        counter = (len / 2) - 1;
    }
    else
    {
        counter = len / 2;
    }
    while (counter--)
    {
        temp = temp->next;
    }
    return temp;
}

int main()
{

    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    // Node *seventh = new Node(70);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;
    // seventh->next = NULL;

    Node *middleList = middleOfLinkedList(first);
    cout << middleList->data;
    Node *middleList2 = middle(first);
    cout << middleList2->data;
    return 0;
}