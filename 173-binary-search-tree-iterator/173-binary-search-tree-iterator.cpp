/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> arr;
    int i;
    void inorder(TreeNode *curr){
        if(curr != NULL){
            inorder(curr->left);
            arr.push_back(curr->val);
            inorder(curr->right);
        }
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
        i = 0;
    }
    
    int next() {
       int x = arr[i];
       i++;
        return x;
    }
    
    bool hasNext() {
        return i < arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */