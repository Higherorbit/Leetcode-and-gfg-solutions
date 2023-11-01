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
    unordered_map<int,int>mp;
    void solve(TreeNode* root){
        if(root==NULL)return ;
        solve(root->left);
        mp[root->val]++;
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        mp.clear();
        solve(root);
        int maxx=0;
        for(auto x:mp){
            if(x.second>maxx){
                maxx=x.second;
            }
        }
        vector<int>ans;
        for(auto x:mp){
            if(x.second==maxx){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};