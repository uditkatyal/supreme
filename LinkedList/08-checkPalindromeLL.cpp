#include <iostream>
using namespace std;

// Approach 1 -> reverse linked list , store it and compare with original
// time and space -> linear complexity

// Approach 2 -> find mid, reverse other half , comapre both half
// time -> linear but space optimised -> (constant space)

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

bool checkPalindrome(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return true;
    }

    // Step A: middle find out krlo
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *middle = slow;

    // Step B: reverse after the middle node (the other half)
    Node *prev = NULL;
    Node *curr = middle->next;
    Node *forward = curr;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    // this connection is optional not required
    middle->next = prev;

    // step C : compare both half

    Node *temp1 = head;
    Node *temp2 = prev;

    while (temp2 != NULL)
    {
        cout << temp1->data << " " << temp2->data << endl;
        if (temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(30);
    Node *fifth = new Node(20);
    Node *sixth = new Node(10);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    print(first);
    cout << endl;

    if (checkPalindrome(first))
    {
        cout << "LL is a palindrome" << endl;
    }
    else
    {
        cout << "LL is not a palindrome" << endl;
    }
    return 0;
}