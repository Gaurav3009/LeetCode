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
    vector<string> res;
    vector<int> path;
    void inorder(TreeNode *curr){
        if(!curr){
            return;
        }
        if(!curr->left && !curr->right){
            path.push_back(curr->val);
            string s = "";
            for(int i = 0; i < path.size(); i++){
                s += to_string(path[i]) + "->";
            }
            s.pop_back();s.pop_back();
            res.push_back(s);
            path.pop_back();
            return;
        }
        path.push_back(curr->val);
        inorder(curr->left);
        inorder(curr->right);
        path.pop_back();
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        inorder(root);
        return res;
    }
};