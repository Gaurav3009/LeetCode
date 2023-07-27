//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
        if((m >= n) || head ==  NULL || head->next == NULL) {
            return head;
        } 
        int i = 1;
        Node *p = NULL, *start = head;
        while(start != NULL) {
            if(i == m) {
                break;
            }
            i++;
            p = start;
            start = start->next;
        }
        Node *last = start;
        while(last != NULL) {
            if(i == n) {
                break;
            }
            i++;
            last = last->next;
        }
        Node *ne = last->next;
        last->next = NULL;
        
        while(start != NULL) {
            Node *temp = start->next;
            start->next = ne;
            ne = start;
            start = temp;
        }
        if(p) {
            p->next = ne;
            return head;
        }
        return ne;
    }
};

//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends