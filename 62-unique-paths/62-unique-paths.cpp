class Solution {
public:
    vector<vector<int>>dp;
    int solve(int n, int m){
        if(n==1 or m==1){
            return 1;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        return dp[n][m]=solve(n-1,m)+solve(n,m-1);
    }
    int uniquePaths(int n, int m) {
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(n,m);
    }
};