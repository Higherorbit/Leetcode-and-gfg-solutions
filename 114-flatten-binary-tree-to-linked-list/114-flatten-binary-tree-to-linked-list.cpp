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
    vector<int> v;
    void traverse(TreeNode* root){
        if(root==NULL){
            return ;
        }
        v.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    
    void flatten(TreeNode* root) {
        if(root==NULL){
            return ;
        }
        traverse(root);
        root->val=v[0];
        TreeNode* temp=root;        
        for(int i=1;i<v.size();i++){
            TreeNode* n=new TreeNode();
            n->val=v[i];
            temp->right=n;
            temp->left=NULL;
            temp=n;
        }
    }
};