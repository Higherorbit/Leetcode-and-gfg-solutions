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
    bool ans=false;
    bool check(TreeNode* root,TreeNode* subRoot){
        if(root==NULL and subRoot==NULL){
            return true;
        }
        if(root==NULL and subRoot!=NULL){
            return false;
        }
        if(root!=NULL and subRoot==NULL){
            return false;
        }
        if(root->val!=subRoot->val){
            return false;
        }
        return check(root->left,subRoot->left) and check(root->right,subRoot->right);
    }
    
    void traverse(TreeNode* root,TreeNode* subRoot){
        if(root==NULL){
            return ;
        }
        if(root->val==subRoot->val){
            if(check(root,subRoot)){
                ans=true;
            }
        }
        traverse(root->left,subRoot);
        traverse(root->right,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        traverse(root,subRoot);
        return ans;        
    }
};