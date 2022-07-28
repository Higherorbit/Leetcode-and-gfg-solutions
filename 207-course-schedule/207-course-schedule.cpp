class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int>inDeg(n,0);
        for(auto x:edges){
            adj[x[1]].push_back(x[0]);
            inDeg[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            ans.push_back(t);
            for(auto x:adj[t]){
                inDeg[x]--;
                if(inDeg[x]==0){
                    q.push(x);
                }
            }
        }
        return (ans.size()==n);
        
    }
};