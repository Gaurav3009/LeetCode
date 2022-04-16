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
    TreeNode * inorderpred(TreeNode *root) {
        if(root == NULL){
            return root;
        }
        if(root->right == NULL){
            return root;
        }
        return inorderpred(root->right);
    }
    // TreeNode* deleteNode(TreeNode* root, int key) {
    //     if(root == NULL){
    //         return root;
    //     }
    //     if(root->left == NULL && root->right == NULL){
    //         if(root->val == key){
    //             root = NULL;
    //         }
    //         return root;
    //     }
    //     if(key < root->val){
    //         root->left = deleteNode(root->left, key);
    //     }else if(key > root->val){
    //         root->right = deleteNode(root->right, key);
    //     }else{
    //         TreeNode *p = inorderpred(root->left);
    //         root->val = p->val;
    //         root->left = deleteNode(root->left, p->val);
    //     }
    //     return root;
    // }
    TreeNode *deleteNode(TreeNode *root, int key){
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            return helper(root);
        }
        TreeNode *first = root;
        while(root != NULL){
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }else{
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }
        return first;
    }
    TreeNode * helper(TreeNode *root){
        if(root->left == NULL){
            return root->right;
        }else if(root->right == NULL){
            return root->left;
        }
        TreeNode *rchild = root->right;
        TreeNode *lchild = inorderpred(root->left);
        lchild->right = rchild;
        return root->left;
    }
};