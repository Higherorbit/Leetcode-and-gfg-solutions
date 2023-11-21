class Solution {
public:
    vector<int> par, siz;

    void reset(int n){
        par.assign(n, 0), siz.assign(n, 1);
        for(int i = 0; i < n; i++)
            par[i] = i;
    }

    int getpar(int x){
        if(x == par[x])
            return x;
        par[x] = getpar(par[x]); // path compression heuristic
        return par[x];
    }

    bool merge(int a, int b){
        a = getpar(a), b = getpar(b);
        if(a == b) return false;
        if(siz[a] < siz[b]) // smaller to larger merging heuristic 
            swap(a, b); 
        par[b] = a, siz[a] += siz[b];
        return true;
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size();
        reset(n);
        int ans=n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[i][j]){
                    if(merge(i,j)) ans--;
                }
            }
        }
        return ans;
    }
};