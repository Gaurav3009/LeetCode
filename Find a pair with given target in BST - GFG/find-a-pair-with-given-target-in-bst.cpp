//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
#define MAX_SIZE 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

// } Driver Code Ends
/*Complete the function below
Node is as follows
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    stack<Node*> st1;
    stack<Node*> st2;
    void fillStackLeft(Node *curr) {
        while(curr != NULL) {
            st1.push(curr);
            curr = curr->left;
        }
    }
    void fillStackRight(Node *curr) {
        while(curr != NULL) {
            st2.push(curr);
            curr = curr->right;
        }
    }
    Node* next() {
        if(!st1.empty()) {
            Node* x = st1.top();
            Node *right = st1.top()->right;
            st1.pop();
            if(right) {
                fillStackLeft(right);
            }
            return x;
        }
        return NULL;
    }
    Node* prev() {
        if(!st2.empty()) {
            Node* x = st2.top();
            Node *left = st2.top()->left;
            st2.pop();
            if(left) {
                fillStackRight(left);
            }
            return x;
        }
        return NULL;
    }
    int isPairPresent(struct Node *root, int target) {
        fillStackLeft(root);
        fillStackRight(root);
        Node*first, *last;
        first = next();
        last = prev();
        while(first != last && first && last) {
            // cout<<first->data<<" "<<last->data<<endl;
            if((first->data + last->data) == target) {
                return 1;
            } else if((first->data + last->data) < target) {
                first = next();
            } else if((first->data + last->data) > target) {
                last = prev();
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

       getline(cin, s);
       int k = stoi(s);
        //getline(cin, s);
       Solution obj;    
       cout << obj.isPairPresent(root, k) << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}

// } Driver Code Ends