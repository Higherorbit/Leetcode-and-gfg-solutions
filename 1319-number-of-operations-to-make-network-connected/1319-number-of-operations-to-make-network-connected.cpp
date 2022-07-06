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
    int makeConnected(int n, vector<vector<int>>& v) {
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int extra=0;
        for(int i=0;i<v.size();i++){
            int x=find(v[i][0]);
            int y=find(v[i][1]);
            if(x!=y){
                parent[y]=x;
            }
            else{
                extra++;
            }
        }
        set<int>s;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                s.insert(i);
            }
        }
        int ans=0;
        if(extra>=s.size()-1){
            ans=s.size()-1;
        }
        else{
            ans= -1;
        }
        return ans;
    }
};