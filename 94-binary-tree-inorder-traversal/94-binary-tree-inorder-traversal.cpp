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

// 1. First way
vector<int> ans;
void solve(TreeNode* r){  //O(n)
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
        // 2. Second way
        auto a= inorderTraversal(r->left); //O(n1)
        a.push_back(r->val);               //O(1)
        auto b=inorderTraversal(r-> right);//(n2)
        for(auto &x:b){
            a.push_back(x);                //O(n2)
        }
        return a;                          //O(n1+n2=n)
    }
};