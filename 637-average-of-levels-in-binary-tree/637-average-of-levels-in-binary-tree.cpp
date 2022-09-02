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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>>v;
        vector<double>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){            
            vector<int> temp; 
            int n=q.size();
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
        
        for(int i=0;i<v.size();i++){
            double t=0;
            for(auto x:v[i]){
                t+=x;
            }
            t/=v[i].size();
            ans.push_back(t);
        }
        return ans;
    }
};