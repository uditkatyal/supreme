#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
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

    void print(Node *&head)
    {

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void insertAtHead(Node *&head, Node *&tail, int data)
    {
        // list is empty
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        // list has ele
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtTail(Node *&head, Node *&tail, int data)
    {
        // list is empty
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        // list has ele
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAtPosition(Node *&head, Node *&tail, int data, int position)
    {

        Node *newNode = new Node(data);
        // list is empty
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        // head insertion
        if (position == 1)
        {
            insertAtHead(head, tail, data);
            return;
        }
        // tail insertion
        int len = findLength(head);
        if (position == len + 1)
        {
            insertAtTail(head, tail, data);
            return;
        }
        if (position > len)
        {
            // although len+1 is valid but it is already handled above
            cout << "Invalid position entered" << endl;
            return;
        }
        // in b/w
        int i = 1;
        Node *prevNode = head;
        while (i < position - 1)
        {
            prevNode = prevNode->next;
            i++;
        }
        newNode->next = prevNode->next;
        prevNode->next->prev = newNode;

        prevNode->next = newNode;
        newNode->prev = prevNode;
    }

    void deleteNode(Node *&head, Node *&tail, int position)
    {
        // if ll is empty
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        // 1st ele
        if (position == 1)
        {
            Node *temp = head;

            head = head->next;

            head->prev = NULL;
            temp->next = NULL;

            delete temp;
            return;
        }

        // last ele
        int len = findLength(head);
        if (position == len)
        {
            Node *temp = tail;

            tail = tail->prev;

            tail->next = NULL;
            temp->prev = NULL;

            delete temp;
            return;
        }

        // invalid position
        if (position > len)
        {
            cout << "Invalid position entered" << endl;
            return;
        }

        // in b/w deletion

        int i = 1;
        Node *prevNode = head;
        while (i < position - 1)
        {
            prevNode = prevNode->next;
            i++;
        }

        Node *curr = prevNode->next;

        prevNode->next = curr->next;

        curr->next->prev = prevNode;

        curr->next = NULL;
        curr->prev = NULL;

        delete curr;
        return;
    }
};

int main()
{
    Node list;
    // object of class

    // pointers to Node
    Node *head = NULL;
    Node *tail = NULL;

    list.insertAtHead(head, tail, 10);
    list.insertAtHead(head, tail, 20);
    list.insertAtHead(head, tail, 30);
    list.insertAtHead(head, tail, 40);

    list.print(head);
    cout << endl;

    list.insertAtTail(head, tail, 100);
    list.insertAtTail(head, tail, 200);
    list.insertAtTail(head, tail, 300);
    list.insertAtTail(head, tail, 400);

    list.print(head);
    cout << endl;

    list.insertAtPosition(head, tail, 101, 10);

    list.print(head);
    cout << endl;

    list.deleteNode(head, tail, 8);

    list.print(head);
    cout << endl;

    return 0;
}