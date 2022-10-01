/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* p;                                                                  
    map<TreeNode*,vector<TreeNode*>>mp;
    map<TreeNode*, bool> visited;
    void traverse(TreeNode* root){
        if(root==NULL){
            return ;
        }
        visited[root]=0;
        if(root->left!=NULL){
            mp[root].push_back(root->left);
            mp[root->left].push_back(root);
            traverse(root->left);
        }
        if(root->right!=NULL){
            mp[root].push_back(root->right);
            mp[root->right].push_back(root);
            traverse(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<int,int>dist;
        traverse(root);
        p=target;
        queue<TreeNode*> q;
        q.push(p);
        visited[p]=1;
        dist[target->val]=0;
        
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto t=q.front();
                q.pop();
                for(auto x:mp[t]){
                    if(visited[x]==0){
                        dist[x->val]=dist[t->val]+1;
                        visited[x]=1;
                        q.push(x);
                    }
                }
            }
        }
        vector<int>ans;
        for(auto x:dist){
            // cout<<x.first<<" "<<x.second<<endl;;
            if(x.second==k){
                ans.push_back(x.first);
            }
        }
        // cout<<endl;
        return ans; 
    }
};