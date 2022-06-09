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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
         queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>v;
        while(!q.empty()){
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                auto t=q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left!=NULL){
                    q.push(t->left);
                }
                if(t->right!=NULL){
                  q.push(t->right);
                }
            }
            v.push_back(temp);
        }
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i][v[i].size()-1]);
        }
        return ans;
    }
};