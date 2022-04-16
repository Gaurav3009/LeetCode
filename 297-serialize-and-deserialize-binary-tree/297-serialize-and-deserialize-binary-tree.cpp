/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "";
        }
        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *p = q.front();
            q.pop();
            if(p == NULL){
                s.append("#,");
            }else{
                s.append(to_string(p->val) + ',');
            }
            if(p != NULL){
                q.push(p->left);
                q.push(p->right);
            }
            
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');
        queue<TreeNode *> q;
        int x = stoi(str);
        TreeNode *root = new TreeNode(x);
        q.push(root);
        while(!q.empty()){
            TreeNode *p = q.front();
            q.pop();
            getline(s, str, ',');
            if(str == "#"){
                p->left = NULL;
            }
            else if(str != "#"){
                x =  stoi(str);
                TreeNode *t = new TreeNode(x);
                q.push(t);
                p->left = t;
            }
            getline(s, str, ',');
            if(str == "#"){
                p->right = NULL;
            }
            else if(str != "#"){
                x =  stoi(str);
                TreeNode *t = new TreeNode(x);
                q.push(t);
                p->right = t;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));