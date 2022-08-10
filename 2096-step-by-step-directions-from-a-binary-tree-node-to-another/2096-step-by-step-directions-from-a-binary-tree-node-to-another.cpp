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
    TreeNode* LCA(TreeNode* root,int a, int b){
        if(root==NULL)
            return NULL;
        if(root->val==a or root->val==b){
            return root;
        }
        auto l=LCA(root->left,a,b);
        auto r=LCA(root->right,a,b);
        if(l!=NULL and r!=NULL){
            return root;
        }
        if(l){
            return l;
        }
        return r;
    }
    bool traverse(TreeNode* root, int a,string &s){
        if(root==NULL){
            return false;
        }
        if(root->val==a){
            return true;
        }
        s+="L";
        if(traverse(root->left,a,s)){
            return true;
        }
        s.pop_back();
        s+="R";
        if(traverse(root->right,a,s)){
            return true;
        }
        s.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Very good problem
        // 1. get the LCA
        auto r=LCA(root,startValue,destValue);
        // cout<<r->val<<endl;
        // 2. Now we need to find the path from the LCA to the node
        string s="";
        string t="";
        traverse(r,startValue,s);
        traverse(r,destValue,t);
        // cout<<s<<endl;
        string ans="";
        for(auto &x:s){
            ans+="U";
        }
        return ans+t;
    }
};