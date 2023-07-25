//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node* reverse(Node *head) {
        if(head->next == NULL) {
            return head;
        }
        Node *prev = NULL, *temp;
        while(head != NULL) {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    void rearrange(struct Node *head)
    {
        if(head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }
        Node *curr = head, *prev = NULL, *last = head;
        int i = 1;
        Node *dummy, *res;
        dummy = res = new Node(-1);
        while(curr != NULL) {
            if(i % 2 == NULL) {
                dummy->next = curr;
                dummy = dummy->next;
                curr = curr->next;
                dummy->next = NULL;
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
            i++;
            if(prev->next == NULL) {
                last = prev;
            } else if(prev->next->next == NULL) {
                last = curr;
            }
        }
        res->next = reverse(res->next);
        last->next = res->next;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends