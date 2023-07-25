//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};


// } Driver Code Ends
/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */


//Function to sort the given doubly linked list using Merge Sort.
Node* merge(Node *a, Node *b) {
    if(!a) {
        return b;
    }
    if(!b) {
        return a;
    }
    Node *dummy, *res;
    dummy = res = new Node(-1);
    while(a && b) {
        if(a->data <= b->data) {
            dummy->next = a;
            a->prev = dummy;
            a = a->next;
        } else {
            dummy->next = b;
            b->prev = dummy;
            b = b->next;
        }
        dummy = dummy->next;
        dummy->next = NULL;
    }
    if(a) {
        dummy->next = a;
        a->prev = dummy;
    }
    if(b) {
        dummy->next = b;
        b->prev = dummy;
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
    slow->next->prev = NULL;
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
struct Node *sortDoubly(struct Node *head)
{
	head = mSort(&head);
	head->prev = NULL;
	return head;
}


//{ Driver Code Starts.

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}


// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}

// } Driver Code Ends