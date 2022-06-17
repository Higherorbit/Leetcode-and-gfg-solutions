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
    set<TreeNode*>covered;
    int ans=0;
    void dfs(TreeNode* root, TreeNode* par){
        if(root==NULL){
            return ;
        }
        dfs(root->left,root);
        dfs(root->right,root);
        if(!covered.count(root->left) or !covered.count(root->right) or (!covered.count(root) and par==NULL)){
            covered.insert(root);
            ans++;
            covered.insert(root->left);
            covered.insert(root->right);
            covered.insert(par);
        }
    }
    int minCameraCover(TreeNode* root) {
        covered.insert(NULL);
        dfs(root,NULL);
        return ans;
    }
};