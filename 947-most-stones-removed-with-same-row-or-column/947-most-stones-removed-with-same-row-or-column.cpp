class Solution {
public:        
    vector<int>parent;
    
    int find(int x){
        if(x==parent[x]){
            return x;
        }
        parent[x]=find(parent[x]);
        return parent[x];
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        map<int,int>x;
        map<int,int>y;// {x,i};
        for(int i=0;i<n;i++){
            if(!x.count(stones[i][0])){
                x[stones[i][0]]=i;
            }
            else{
                int ind=x[stones[i][0]];
                parent[find(i)]=parent[find(ind)];
            }
            if(!y.count(stones[i][1])){
                y[stones[i][1]]=i;
            }
            else{
                int ind=y[stones[i][1]];
                parent[find(i)]=parent[find(ind)];
            }            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            // cout<<parent[i]<<" ";
            if(parent[i]==i){
                ans++;
            }
        }
        // cout<<ans<<endl;
        return n-ans;
        
    }
};