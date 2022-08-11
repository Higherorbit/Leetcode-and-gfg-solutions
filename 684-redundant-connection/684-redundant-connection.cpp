class Solution {
public:
    vector<int> parent;
    vector<int>sz;
    int find(int x){     //path compression hueristic
        if(parent[x]==x){// O(log(n))
            return x;
        }
        parent[x]=find(parent[x]);
        return parent[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        sz.resize(n+1,1);        
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            int x=find(edges[i][0]);
            int y=find(edges[i][1]);
            if(x!=y){
                if(sz[x]<sz[y]){
                    swap(x,y);
                }
                parent[y]=x;
                sz[x]+=sz[y];
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