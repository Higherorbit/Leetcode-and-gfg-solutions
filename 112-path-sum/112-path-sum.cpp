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
    set<int>s;
    void traverse(TreeNode* root,int sum){
        if(!root){
            return ;
        }
        if(root->left==NULL and root->right==NULL){
            s.insert(sum);
            return ;
        }
        if(root->left)
            traverse(root->left,sum+root->left->val);
        if(root->right)
            traverse(root->right,sum+root->right->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        traverse(root,root->val);
        return s.count(targetSum);
    }
};