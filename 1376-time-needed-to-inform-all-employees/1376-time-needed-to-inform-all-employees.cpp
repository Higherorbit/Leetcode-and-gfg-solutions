class Solution {
public:        
    vector<int> adj[100005];
    
    int dfs(int managerId,vector<int>&informTime){
        int maxi=0;
        for(auto &i:adj[managerId]){
            maxi=max(maxi,dfs(i,informTime));
        }
        return informTime[managerId]+maxi;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime){
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(headID,informTime);
    }
};