class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int s) {
        vector<pair<int,int>>adj[n];
        for(auto x:times){
            adj[x[0]-1].push_back({x[1]-1,x[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[s-1]=0;
        pq.push({0,s-1});
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            for(auto x:adj[u]){
                int v=x.first;
                int w=x.second;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        // for(auto x:dist)cout<<x<<" ";
        int ans=*max_element(dist.begin(),dist.end());
        return (ans==INT_MAX? -1: ans);
                    
    }
};