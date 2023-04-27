#include <iostream>
#include <unordered_map>
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

// method 1 - Using two nested Loops
// method 2 - Using maps (implemented below)
// method 3 - Sort the list and then apply rem dup from Sorted LL

void removeDup(Node *&head)
{
    // empty list
    if (head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    unordered_map<int, bool> mp;

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (mp.find(temp->data) == mp.end())
        {
            mp.insert({temp->data, true});
            // mp[temp->data] = true;
            prev = temp;
        }
        else
        {
            Node *ptr = temp;
            prev->next = temp->next;
            ptr->next = NULL;
            delete ptr;
        }
        // IMP temp will be updated by prev->next (DRY RUN)!
        temp = prev->next;
    }
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

    removeDup(first);

    print(first);
    return 0;
}