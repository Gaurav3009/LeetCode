//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *random;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    random = NULL;
	}
};
int checkcloned(Node* a, Node *b)
{
	if ((a == NULL and b == NULL))
		return 1;

	if (a != NULL && b != NULL)
	{
		int t = (a->data == b->data && checkcloned(a->left, b->left) && checkcloned(a->right, b->right));

		if (a->random != NULL && b->random != NULL)
			return (t && a->random->data == b->random->data);
		if (a->random == b->random)
			return t;

		return 0;
	}

	return 0;

}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

class Solution{
  public:
    /* The function should clone the passed tree and return 
       root of the cloned tree */
        Node* inorder(Node *tree, Node *root, map<Node*, Node*> hashMap) {
        if(root) {
            inorder(tree->left, root->left, hashMap);
            if(hashMap.find(tree->random) != hashMap.end()) {
                root->random = hashMap[tree->random];
            } 
            inorder(tree->right, root->right, hashMap);
        }
        return root;
    }
    Node* cloneTree(Node* tree) {
        if(tree == NULL) {
            return NULL;
        }
        Node *root = new Node(tree->data);
        queue<Node*> q1;
        queue<Node*> q2;
        q1.push(tree);
        q2.push(root);
        map<Node*, Node*> hashMap;
        hashMap[tree] = root;
        while(!q1.empty()) {
            Node *p = q1.front();
            q1.pop();
            Node *dum = q2.front();
            q2.pop();
            if(p->left) {
                q1.push(p->left);
                dum->left = new Node(p->left->data);
                q2.push(dum->left);
                hashMap[p->left] = dum->left;
            }
            if(p->right) {
                q1.push(p->right);
                dum->right = new Node(p->right->data);
                q2.push(dum->right);
                hashMap[p->right] = dum->right;
            }
        }
        root = inorder(tree, root, hashMap);
        return root;
        
    }
};


//{ Driver Code Starts.
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L'){
          parent->left = child;
           m[n2]  = child;
        }
        else if(lr=='R'){
          parent->right = child;
           m[n2]  = child;
        }
        else{
          parent->random = m[n2];
        }


     }
     Solution obj;
     Node *t = obj.cloneTree(root);
     if(t==root)
        cout<<0<<endl;
     else
     cout<<checkcloned(root,t);
     cout<<"\n";
  }
  return 0;
}


// } Driver Code Ends