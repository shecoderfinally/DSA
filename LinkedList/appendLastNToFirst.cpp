#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        delete next;
    }
};

Node *takeInput(vector<int> &arr)
{
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        if (head == NULL && tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthLL(Node *head)
{
    if (head == NULL)
        return 0;
    return lengthLL(head->next) + 1;
}

Node *appendLastNToFirst(Node *head, int n)
{
    if (head == NULL || n == 0)
        return head;
    int i = 0, len = lengthLL(head);
    Node *temp = head;
    while (temp != NULL && i < len - n - 1)
    {
        temp = temp->next;
        i++;
    }
    Node *newHead = temp->next;
    temp->next = NULL;
    temp = newHead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    return newHead;
}

int main()
{
    vector<int> arr1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head1 = takeInput(arr1);
    head1 = appendLastNToFirst(head1, 3);
    printLL(head1);
    delete head1;
    return 0;
}
