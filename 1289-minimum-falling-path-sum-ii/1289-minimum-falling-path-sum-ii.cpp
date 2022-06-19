class Solution {
public:
    const int inf=2e4+2;
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int dp[n+2][m+2];
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++){
                if(i==1){
                    dp[i][j]=mat[i-1][max(0,min(m-1,j-1))];
                }
                if(i==0 or j==0){
                    dp[i][j]=inf;
                }
                
                if(j==m+1){
                    dp[i][j]=inf;
                }
                
            }
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                dp[i][j]=mat[i-1][j-1];
                int t=inf;
                for(int k=1;k<=m;k++){
                    if(k==j){
                        continue;
                    }
                    t=min(t,dp[i-1][k]);
                }
                dp[i][j]+=t;
            }
        }
        int ans=inf;
        // for(int i=0;i<=n+1;i++){
        //     for(int j=0;j<=m+1;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int j=1;j<=m;j++){
            ans=min(ans,dp[n][j]);
        }
        return ans;
    }
};