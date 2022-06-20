class Solution {
public:
    int cnt=0;
    int n=0;
    void solve(vector<int>&v, int s, int i, int t){
        if(i>n){
            return ;
        }
        if(i==n and t==s){
            cnt++;
        }
        if(i<n)
        {solve(v,s,i+1,t+v[i]);       
        solve(v,s,i+1,t-v[i]);}

    }
    int findTargetSumWays(vector<int>& v, int s) {
        n=v.size();
        solve(v,s,0,0);
        return  cnt;
    }
};