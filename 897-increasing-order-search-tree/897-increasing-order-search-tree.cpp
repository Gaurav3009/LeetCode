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
class Solution {
public:
    vector<int> arr;
    void inorder(TreeNode *curr){
        if(curr != NULL){
            inorder(curr->left);
            arr.push_back(curr->val);
            inorder(curr->right);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        root = new TreeNode(arr[0]);
        TreeNode *curr = root;
        for(int i = 1; i < arr.size(); i++){
            TreeNode *t = new TreeNode(arr[i]);
            curr->right = t;
            curr = t;
        }
        return root;
    }
};