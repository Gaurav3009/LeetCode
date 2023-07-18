//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
       int N = 0;
       node *curr = head;
       while(curr != NULL) {
           N++;
           curr = curr->next;
       }
       int g = N / k;
       node *temp, *prev = NULL, *start, *last;
       curr = head;
       int t;
       for(int i =1; i <= N; i+= k) {
           start = curr;
           t = k;
           while(curr != NULL) {
               temp = curr->next;
               curr->next = prev;
               prev = curr;
               curr = temp;
               t--;
               if(t == 0) {
                   break;
               }
           }
           if(i == 1) {
               head = prev;
           } else {
               last->next = prev;
           }
           start->next = curr;
           last = start;
           prev = NULL;
       }
       return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends