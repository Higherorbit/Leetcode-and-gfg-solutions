class Solution {
public:
    vector<string> v;
    map<int,string>mp;
    void traverse(TreeNode* root, string t){
        if(root->left==NULL and root->right==NULL){
            v.push_back(t);
            return ;
        }
        if(root->left){
            traverse(root->left,t+mp[root->left->val]);
        }
        if(root->right){
            traverse(root->right,t+mp[root->right->val]);
        }
    }
    
    string smallestFromLeaf(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        for(int i=0;i<=25;i++){
            mp[i]='a'+i;
        }
        traverse(root,mp[root->val]);
        for(auto &x:v){
            reverse(x.begin(),x.end());
        }
        sort(v.begin(),v.end());
        return v[0];
    }
};