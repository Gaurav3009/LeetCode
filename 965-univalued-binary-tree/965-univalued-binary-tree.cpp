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
    map<int, int> m;
    void inorder(TreeNode *curr){
        if(curr){
            inorder(curr->left);
            m[curr->val]++;
            inorder(curr->right);
        }
    }
    bool isUnivalTree(TreeNode* root) {
        inorder(root);
        return m.size() == 1;
    }
};