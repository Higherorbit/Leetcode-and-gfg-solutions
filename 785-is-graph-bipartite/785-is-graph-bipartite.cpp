class Solution {
public:
    vector<int>color;
    bool dfs(vector<vector<int>>& graph,int i){
        for(auto x:graph[i]){
            if(color[x]==0){
                color[x]=-color[i];
                if(dfs(graph,x)){
                    return true;
                }
            }
            else{
                if(color[x]==(color[i])){
                    return true;
                }
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        color.resize(n,0);
        for(int i=0;i<n;i++){
            if(color[i]==0){
                color[i]=1;
                if(dfs(graph,i)){
                    return false;
                }
            }
        }
        return true;
    }
};