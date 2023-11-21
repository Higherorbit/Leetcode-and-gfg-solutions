class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size();
        parent.resize(n+1);
        int ans=n;
        for(int i=0;i<=n;i++) parent[i]=i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[i][j]){
                    int x=find(i+1),y=find(j+1);
                    if(x!=y){
                        parent[y]=x;
                        ans--;
                    }
                }
            }
        }
        return ans;
    }
};