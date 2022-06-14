class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n+1][6];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=5;j++){
                dp[i][j]=0;
            }
        }
        for(int j=1;j<=5;j++){
            dp[1][j]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=5;j++){
                for(int k=j;k>=0;k--){
                    dp[i][j]+=dp[i-1][k];
                    cout<<dp[i][j]<<endl;
                }
                // cout<<dp[i][j]<<endl;
            }
        }
        int ans=0;
        for(int j=1;j<=5;j++){
            ans+=dp[n][j];
        }
        return ans;
    }
};