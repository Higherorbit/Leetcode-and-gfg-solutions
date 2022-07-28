class Solution {
public:
    vector<int>color;
    bool dfs(vector<vector<int>>& graph,int i,int clr){
        color[i]=clr;
        for(auto x:graph[i]){
            if(color[x]==0){
                if(dfs(graph,x,-clr)){
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
                if(dfs(graph,i,1)){
                    return false;
                }
            }
        }
        return true;
    }
};