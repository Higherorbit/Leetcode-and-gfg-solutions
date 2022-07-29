class Solution {
public:
    bool canCross(vector<int>& v) {
        int n=v.size();
        vector<vector<bool>>dp(n,vector<bool>(n+1,0));
        if(v[1]-v[0]==1){
            dp[1][1]=1;
        }
        for(int i=2;i<n;i++){
            for(int j=1;j<i;j++){
                int diff=v[i]-v[j];
                if(diff<=i){
                    dp[i][diff]=dp[j][diff-1] or dp[j][diff] or dp[j][diff+1];
                }
            }
        }
        for(auto x:dp[n-1]){
            if(x){
                return true;
            }
        }
        return false;
    }
};