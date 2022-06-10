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
    vector<vector<int>>v;
    void traverse(TreeNode* root, vector<int>&t){
        if(root->left==NULL and root->right==NULL){
            v.push_back(t);
        }
        if(root->left){
            t.push_back(root->left->val);
            traverse(root->left,t);
            t.pop_back();
        }
        if(root->right){
            t.push_back(root->right->val);
            traverse(root->right,t);
            t.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return {};
        }
        vector<int>t;
        t.push_back(root->val);
        traverse(root,t);
        vector<vector<int>>ans;
        for(auto i:v){
            int s=0;
            for(auto x:i)
                s+=x;
            if(s==targetSum){
                ans.push_back(i);
            }
        }
        return ans;
    }
};