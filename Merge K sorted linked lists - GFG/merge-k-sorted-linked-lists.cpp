//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* merge(Node *s1, Node *s2) {
        if(!s1) {
            return s2;
        }
        if(!s2) {
            return s1;
        }
        Node *dummy = new Node(-1);
        Node *res = dummy;
        while(s1 && s2) {
            if(s1->data <= s2->data) {
                dummy->next = s1;
                s1 = s1->next;
            } else {
                dummy->next = s2;
                s2 = s2->next;
            }
            dummy = dummy->next;
            dummy->next = NULL;
        }
        if(s1) {
            dummy->next = s1;
        }
        if(s2) {
            dummy->next = s2;
        }
        return res->next;
    }
    Node * mergeKLists(Node *arr[], int K)
    {
           if(K == 1) {
               return arr[0];
           }
           int i = 0;
           Node *head = NULL;
           while(i < K) {
               head = merge(head, arr[i]);
               i++;
           }
           return head;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends