//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    if(head == NULL) {
        return head;
    }
    Node *small, *s;
    Node *equal, *e;
    Node *big, *b;
    small = s = new Node(-1);
    equal = e = new Node(-1);
    big = b = new Node(-1);
    while(head != NULL) {
        if(head->data < x) {
            s->next = head;
            s = s->next;
        } else if(head->data > x) {
            b->next = head;
            b = b->next;
        } else {
            e->next = head;
            e = e->next;
        }
        Node *temp =  head->next;
        head->next = NULL;
        head = temp;
    }
    if(small->next) {
        head = small->next;
        if(equal->next) {
            s->next = equal->next;
            if(big->next) {
                e->next = big->next;
            }
        } else {
            s->next = big->next;
        }
    } else if(equal->next) {
        head = equal->next;
        e->next = big->next;
    } else {
        head = big->next;
    }
    return head;
}