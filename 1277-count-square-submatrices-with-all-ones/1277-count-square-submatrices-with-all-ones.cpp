class Solution {
public:
    int countSquares(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(v[i-1][j-1]==1){
                    dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};