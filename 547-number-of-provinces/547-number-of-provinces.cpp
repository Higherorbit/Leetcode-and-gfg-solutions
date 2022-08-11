class Solution {
public:
    vector<int>parent;
    vector<int>sz;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        parent[x]=find(parent[x]);
        return parent[x];        
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size();
        parent.resize(n+1);
        sz.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        int ans=n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[i][j]==1){
                    int x=find(i+1);
                    int y=find(j+1);
                    if(x!=y){
                        if(sz[x]<sz[y]){
                            swap(x,y);
                        }
                        parent[x]=y;
                        sz[x]+=sz[y];
                        ans--;
                    }
                }
            }
        }
        return ans;
    }
    
};