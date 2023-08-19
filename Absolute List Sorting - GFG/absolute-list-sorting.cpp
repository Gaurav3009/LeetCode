//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution{
    
public:
    // Node* insert(Node *node, Node *root) {
    //     if(root == NULL) {
    //         return node;
    //     }
    //     if(root->data >= node->data) {
    //         node->next = root;
    //         return node;
    //     }
    //     Node *prev = NULL, *curr = root;
    //     while(curr != NULL && curr->data < node->data) {
    //         prev = curr;
    //         curr = curr->next;
    //     }
    //     prev->next = node;
    //     node->next = curr;
    //     return root;
    // }
    Node* merge(Node *s1, Node *s2) {
        if(!s1) {
            return s2;
        }
        if(!s2) {
            return s1;
        }
        Node *s3 = NULL, *last;
        if(s1->data <= s2->data) {
            s3 = s1;
            s1 = s1->next;
        } else {
            s3 = s2;
            s2 =s2->next;
        }
        last = s3;
        last->next = NULL;
        while(s1 && s2) {
            if(s1->data <= s2->data) {
                last->next = s1;
                s1 = s1->next;
            } else {
                last->next = s2;
                s2 = s2->next;
            }
            last = last->next;
            last->next = NULL;
        }
        while(s1) {
            last->next = s1;
            last = last->next;
            s1 = s1->next;
        }
        while(s2) {
            last->next = s2;
            last = last->next;
            s2 = s2->next;
        }
        return s3;
    }
    Node *getMid(Node *head) {
        Node *slow, *fast;
        slow = fast = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    Node* sortList(Node* head) {
        // Node *root = NULL;
        // while(head) {
        //     Node *temp = head->next;
        //     head->next = NULL;
        //     root = insert(head, root);
        //     head = temp;
        // }
        // return root;
        if(head->next != NULL) {
            Node *mid = getMid(head);
            Node *right = mid->next;
            mid->next = NULL;
            head = sortList(head);
            right = sortList(right);
            head = merge(head, right);
        }
        return head;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		// printList(head);
		
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}

// } Driver Code Ends