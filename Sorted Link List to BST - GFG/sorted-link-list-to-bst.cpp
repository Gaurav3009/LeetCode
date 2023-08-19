//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


// } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
    pair<LNode*,LNode*> getMid(LNode* head) {
        LNode *slow, *fast;
        slow = fast = head;
        LNode *prev = NULL;
        while(fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        return {prev, slow};
    }
    TNode* listToBST(LNode *head) {
        if(!head) {
            return NULL;
        }
        if(!head->next) {
            return new TNode(head->data);
        }
        pair<LNode*, LNode*> p = getMid(head);
        LNode *prev = p.first, *mid = p.second;
        TNode *root = new TNode(mid->data);
        if(prev) {
            prev->next = NULL;
            root->left = listToBST(head);
        }
        if(mid->next) {
            LNode *temp = mid->next;
            mid->next = NULL;
            root->right = listToBST(temp);
        }
        return root;
    }
    TNode* sortedListToBST(LNode *head) {
        return listToBST(head);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}

// } Driver Code Ends