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
    vector<int> vec;
    void inorder(TreeNode *curr){
        if(curr != NULL){
            inorder(curr->left);
            vec.push_back(curr->val);
            inorder(curr->right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return vec[k - 1];
    }
};