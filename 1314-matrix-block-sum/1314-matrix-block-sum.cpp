class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& v, int k) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>>sum(n+1,vector<int>(m+1,0));
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum[i][j]=v[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int r1=max(0,i-k);
                int r2=min(n-1,i+k);
                int c1=max(0,j-k);
                int c2=min(m-1,j+k);
                r1++;
                r2++;
                c1++;
                c2++;
                dp[i][j]=sum[r2][c2]-sum[r1-1][c2]-sum[r2][c1-1]+sum[r1-1][c1-1];
            }
        }
        return dp;
    }
    
};