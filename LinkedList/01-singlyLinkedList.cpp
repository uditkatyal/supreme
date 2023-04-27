// implementation of singly linked list
// insertion and deletion using position
// can also be done through values
// TODO -> add all fucntions inside class make it look more modular and obeying encapsulation
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
    ~Node()
    {
        int val = this->data;

        // although at every deletion i m making node->next = Null and then deleting
        // this is what we are doing here as well
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory free for node with data " << val << endl;
        // if i delete this it will call infinite loop
        // delete temp will call its destructor and delete this inside destructor will
        // call destructor again (leading to infinite calls)
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

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    // if list is empty
    // this is done just to update tail for every insertion at head
    if (head == NULL)
    {
        tail = newNode;
        // no need to write for head coz its handled below
    }

    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    // check if list is empty
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // we are following one based positioning
    // if list empty
    // yahan position matter nhi krti, will straight create single node
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    // insertAtHead
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    // not insertAt Tail but if position goes beyond length

    int len = findLength(head);

    if (position == len + 1)
    {
        insertAtTail(head, tail, data);
        return;
    }
    if (position > len + 1)
    {
        cout << "Enter valid position" << endl;
        // or either we can also insert it at the end (done by babbar)
        // insertAtTail(head, tail, data);
        return;
    }

    // insertionAtTail

    // insertion in b/w
    int i = 1;
    Node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    newNode->next = prev->next;
    prev->next = newNode;
}

void deleteNode(Node *&head, Node *&tail, int position)
{

    // if list is empty
    if (head == NULL)
    {
        cout << "No data to delete" << endl;
        return;
    }

    // first ele
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int len = findLength(head);
    // last ele
    if (position == len)
    {
        Node *prev = head;
        while (prev->next->next != NULL)
        {
            prev = prev->next;
        }
        Node *temp = tail;
        prev->next = NULL;
        tail = prev;
        delete temp;
        return;
    }
    // inavalid position
    if (position > len)
    {
        cout << "Invalid postion entered" << endl;
        return;
    }
    // in b/w position
    Node *prev = head;
    int i = 1;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);

    insertAtTail(head, tail, 100);
    insertAtTail(head, tail, 200);
    insertAtTail(head, tail, 300);

    print(head);
    cout << endl;
    insertAtPosition(head, tail, 3, 999);
    print(head);
    cout << endl;
    insertAtPosition(head, tail, 9, 888);

    print(head);
    cout << endl;

    deleteNode(head, tail, 7);

    print(head);
    return 0;
}