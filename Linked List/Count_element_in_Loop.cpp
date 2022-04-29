// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node *head);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;

        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        cout << countNodesinLoop(head) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// Function to find the length of a loop in the linked list.
int count(Node *node)
{
    int c = 1;
    Node *temp = node;
    while (temp->next != node)
    {
        c++;
        temp = temp->next;
    }
    return c;
}
int countNodesinLoop(struct Node *head)
{
    // Code here
    Node *temp1 = head, *temp2 = head;
    while (temp1 && temp2 && temp2->next)
    {
        temp1 = temp1->next;
        temp2 = temp2->next->next;
        if (temp1 == temp2)
            return count(temp1);
    }
    return 0;   //return 0 if no loop is present in list.
}
