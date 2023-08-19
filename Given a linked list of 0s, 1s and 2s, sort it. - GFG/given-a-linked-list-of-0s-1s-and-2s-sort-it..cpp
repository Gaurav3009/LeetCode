//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node *zero, *z;
        Node *one, *o;
        Node *two, *t;
        z = zero = new Node(-1);
        o = one = new Node(-1);
        t = two = new Node(-1);
        while(head) {
            Node *temp = head->next;
            if(head->data == 0) {
                z->next = head;
                z = z->next;
                z->next = NULL;
            } else if(head->data == 1) {
                o->next = head;
                o = o->next;
                o->next = NULL;
            } else if(head->data == 2) {
                t->next = head;
                t = t->next;
                t->next = NULL;
            }
            head = temp;
        }
        if(zero->next) {
            head = zero->next;
            if(one->next) {
                z->next = one->next;
                o->next = two->next;
            } else {
                z->next = two->next;
            }
        } else if(one->next) {
            head = one->next;
            o->next = two->next;
        } else {
            head = two->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends