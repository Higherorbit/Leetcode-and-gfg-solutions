class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        parent[x]=find(parent[x]);
        return parent[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            int x=find(edges[i][0]);
            int y=find(edges[i][1]);
            if(x!=y){
                parent[y]=x;
            }
            else{
                res.push_back(edges[i][0]);
                res.push_back(edges[i][1]);
                break;
            }
        }
        return res;
    }
};