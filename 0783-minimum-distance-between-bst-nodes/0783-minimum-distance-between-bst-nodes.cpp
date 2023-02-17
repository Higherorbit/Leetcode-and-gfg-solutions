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
    void traverse(TreeNode* root,vector<int> &v){
        if(root==NULL){
            return ;
        }
        v.push_back(root->val);
        traverse(root->right,v);
        traverse(root->left,v);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        traverse(root,v);
        sort(v.begin(),v.end());
        int ans=INT_MAX;
        int n=v.size();
        for(int i=1;i<n;i++){
            ans=min(ans,v[i]-v[i-1]);
        }
        return ans;
    }
};