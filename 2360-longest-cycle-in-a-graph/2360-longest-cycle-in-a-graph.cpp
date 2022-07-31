class Solution {
public:
    vector<bool>visited;
    vector<bool>recSt;
    int ans=1;
    int n;
    vector<bool>c;
    
    // if cycle exists, then the length is 
    int len(vector<int>&edges,int i){
        if(c[i]){
            return 0;
        }
        c[i]=true;
        int adj=edges[i];
        return 1+len(edges,adj);
    }
    
    // to check if cycle exists or not
    bool dfs(vector<int>& edges, int i){ // standard dfs method to check if the cycle exists or not
        visited[i]=true;
        recSt[i]=true;
        int adj=edges[i];
        if(adj!=-1){
            if(visited[adj]==false){
                if(dfs(edges,adj)){
                    ans=max(ans,len(edges,adj));
                    return true;
                }
            }
            else{
                if(recSt[adj]){
                    int k=len(edges,adj);
                    ans=max(ans,k);
                    return true;
                }
            }
        }
        recSt[i]=false;
        return false;
    }
    int longestCycle(vector<int>& edges) {
        n=edges.size();
        visited.resize(n,false);
        recSt.resize(n,false);
        c.resize(n,false);// used for length calculations
        int bigAns=-1;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                if(dfs(edges,i)){
                    bigAns=max(bigAns,ans);
                }
            }
        }
        return bigAns;
    }
};