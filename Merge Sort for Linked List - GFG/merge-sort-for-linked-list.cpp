//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* merge(Node *a, Node *b) {
        if(!a) {
            return b;
        }
        if(!b) {
            return a;
        }
        Node *dummy, *res;
        res = dummy = new Node(-1);
        while(a && b) {
            if(a->data <= b->data) {
                dummy->next = a;
                a = a->next;
            } else {
                dummy->next = b;
                b = b->next;
            }
            dummy = dummy->next;
            dummy->next = NULL;
        }
        if(a) {
            dummy->next = a;
        }
        if(b) {
            dummy->next = b;
        }
        return res->next;
    } 
    void splitList(Node *head, Node **a, Node **b) {
        Node *fast, *slow;
        fast = slow = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        *a = head;
        *b = slow->next;
        slow->next = NULL;
    }
    Node* mSort(Node **headRef) {
        Node *head, *a, *b;
        head = *headRef;
        if(head->next == NULL) {
            return head;
        }
        splitList(head, &a, &b);
        a = mSort(&a);
        b = mSort(&b);
        head = merge(a, b);
        return head;
    }
    Node* mergeSort(Node* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        return mSort(&head);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends