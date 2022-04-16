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
    int ind = 0;
    void inorder(TreeNode* curr){
        if(curr != NULL){
            inorder(curr->left);
            arr.push_back(curr->val);
            inorder(curr->right);
        }
    }
    void set_val(TreeNode* curr){
        if(curr != NULL){
            set_val(curr->left);
            curr->val = arr[ind++];
            set_val(curr->right);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        for(int i = arr.size() - 2; i >= 0; i--){
            arr[i] += arr[i + 1];
            // cout<<" "<<arr[i + 1];
        }
        set_val(root);
        return root;
    }
};