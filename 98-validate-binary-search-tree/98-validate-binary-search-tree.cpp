class Solution {
public:
    vector<int> v;
    void traverse(TreeNode* root){
        if(root==NULL){
            return ;
        }
        traverse(root->left);
        v.push_back(root->val);
        traverse(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        traverse(root);
        set<int>s;
        for(auto x:v){
            s.insert(x);
        }
        if(s.size()!=v.size())
        return false;
        return is_sorted(v.begin(),v.end());
    }
    
};