class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        bool dp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=false;
            }
        }
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
            }
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j=i+k-1;
                if(dp[i+1][j-1] and s[i]==s[j]){
                    dp[i][j]=true;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // cout<<dp[i][j]<<" ";
                if(dp[i][j])ans++;
            }
            // cout<<endl;
        }
        return ans;
    }
};