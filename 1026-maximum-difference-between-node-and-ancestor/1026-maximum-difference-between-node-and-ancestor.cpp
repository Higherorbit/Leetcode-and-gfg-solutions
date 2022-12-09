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
    int ans=INT_MIN;
    void traverse(TreeNode* root, multiset<int>&s){
        if(root==NULL){
            return ;
        }
        int bhalue=root->val;
        int first=*s.begin(), last=*s.rbegin();
        ans=max(ans,max(abs(bhalue-first),abs(bhalue-last)));
        s.insert(bhalue);
        traverse(root->left,s);
        traverse(root->right,s);
        auto itr = s.find(bhalue);
        if(itr!=s.end()){
            s.erase(itr);
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        multiset<int>s;
        s.insert(root->val);
        ans=INT_MIN;
        traverse(root,s);
        return ans;
    }
};