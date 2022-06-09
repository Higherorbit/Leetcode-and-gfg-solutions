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
    vector<int> v;
    void traverse(TreeNode* root){
        if(root==NULL) return ;
        traverse(root->left);
        v.push_back(root->val);
        traverse(root->right);
    }
    void find(TreeNode* root,int a, int b){
        if(root==NULL){
            return ;
        }
        find(root->left,a,b);
        if(root->val==a){
            root->val=b;
        }
        else if(root->val==b){
            root->val=a;
        }
        find(root->right,a,b);
    }
    void recoverTree(TreeNode* root) {
        traverse(root);
        int one=0;
        bool b =true;
        int two=0;
        int prev=INT_MIN;
        for(int i=0;i<v.size();i++){
            if(v[i]<prev){
                if(b){
                    one=prev;
                    b=false;
                }
                two=v[i];
            }
            prev=v[i];
        }
        find(root,one,two);
        
    }
};