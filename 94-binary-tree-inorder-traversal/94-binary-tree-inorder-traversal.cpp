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
vector<int> ans;
void solve(TreeNode* r){
    if(r==NULL) return;
    solve(r->left);
    ans.push_back(r->val);
    solve(r-> right);
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* r) {
        if(r==NULL) return{};
        ans.clear();
        // solve(r);
        auto a= inorderTraversal(r->left);
        a.push_back(r->val);
        auto b=inorderTraversal(r-> right);
        for(auto &x:b){
            a.push_back(x);
        }
        return a;
    }
};