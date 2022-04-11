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
// Solved using preorder Traversal and concept of Backtracking
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    void preorder(TreeNode *curr, int targetSum){
        if(curr == NULL){
            return;
        }
        if(curr->left == NULL && curr->right == NULL){
            path.push_back(curr->val);
            sum += curr->val;
            if(sum == targetSum){
                res.push_back(path);
            }
            sum -= curr->val;
            path.pop_back();
            return;
        }
        path.push_back(curr->val);
        sum += curr->val;
        preorder(curr->left, targetSum);
        preorder(curr->right, targetSum);
        path.pop_back();
        sum -= curr->val;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        preorder(root, targetSum);
        return res;
    }
};