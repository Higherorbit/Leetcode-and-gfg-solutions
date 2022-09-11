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
    void traverse(TreeNode* r, vector<int>&v){
        if(r==NULL){
            return ;
        }
        v.push_back(r->val);
        traverse(r->left,v);
        traverse(r->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        traverse(root,v);
        set<int>s;
        
        for(int i=0;i<v.size();i++){
            s.insert(v[i]);
            if(s.count(k-v[i]) and (2*v[i]!=k)){
                return true;
            }
        }
        return false;        
    }
};