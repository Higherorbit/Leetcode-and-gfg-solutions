class Solution {
public:        
    vector<int> adj[100005];
    
    int dfs(int headID, vector<int>& informTime){
        int maxi=0;
        for(auto i:adj[headID]){
            maxi=max(maxi,dfs(i,informTime));
        }
        return maxi+informTime[headID];
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