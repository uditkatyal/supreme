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

Node *reverseKGroups(Node *&head, int k)
{
    // ll is empty (remember this is not a base case so we are checking if forward exists before calling recursive func)
    if (head == NULL)
    {
        cout << "list is empty" << endl;
        return NULL;
    }
    // remove this if condition if we want to reverse the leftover
    if (k > findLength(head))
    {
        return head;
    }

    // for len >=k
    // ek case hum solve krnege
    // step A: reverse first k nodes
    Node *prev = NULL;
    Node *forward = NULL;
    Node *curr = head;

    int counter = 0;
    while (curr != NULL && counter < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        counter++;
    }
    // check for further nodes unless it will always pass into head == NULL which is edge case not base case!
    // Step B: find recursion ka ans
    if (forward != NULL)
    {
        Node *recursionKaAns = reverseKGroups(forward, k);
        // connect your ans with recursionKaAns
        head->next = recursionKaAns;
    }
    // new head after reversing
    return prev;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = NULL;

    print(first);
    cout << endl;
    first = reverseKGroups(first, 7);

    print(first);
    return 0;
}