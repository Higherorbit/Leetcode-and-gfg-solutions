// dp[i]=1 means i is a safe node
// dp[i]=-1 means i is not a safe node
// dp[i]=0 means we dont now it yet

class Solution {
public:
    int n;
    vector<int>dp;
    bool dfs(vector<vector<int>>& adj,int i){
        if(dp[i]){
            return dp[i]==1;
        }
        dp[i]=-1;
        for(auto x:adj[i]){
            if(!dfs(adj,x)){
                return false;
            }
        }
        dp[i]=1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj){
        n=adj.size();
        dp.resize(n,0);
        for(int i=0;i<n;i++){
            if(adj[i].size()==0){
                dp[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(dp[i]==0){
                dfs(adj,i);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dp[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};