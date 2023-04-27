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

// 2) method Using MAP - find loop exists

// 1) FIND LOOP EXISTS IN LIST
// Floyd's Cycle Detection
bool checkForLoop(Node *&head)
{
    if (!head)
    {
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    // with each pass distance between fast and slow pointer is decreased by one.
    // and if loop exists they will meet at a point
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

// using floyd's cycle method only
// 2) find the starting point of the loop
// mathematical proof
// fast pointer distance = 2*(distance covered by slow pointer)

Node *startingPoint(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL & fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            slow = head;
            break;
        }
    }
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// remove loop
void removeLoop(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL & fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            slow = head;
            break;
        }
    }
    // Node *prev = fast;
    while (slow->next != fast->next)
    {
        // prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
    return;
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
    fifth->next = second;

    // print(first);
    cout << endl;

    cout << checkForLoop(first) << endl;
    cout << startingPoint(first)->data << endl;
    removeLoop(first);
    print(first);
    cout << endl;
    cout << checkForLoop(first) << endl;

    return 0;
}