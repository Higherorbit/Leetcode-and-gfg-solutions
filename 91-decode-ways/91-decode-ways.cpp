/*
dp[i][1] means i am joining it with the previous one
dp[i][0] means i am not joining it with the previous one

dp[i][1]=dp[i-1][0]; If(s[i-1]!='0')
dp[i][0]=dp[i-1][0]+dp[i-1][1];

*/

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        int dp[n][2];
        if(s[0]!='0'){
            dp[0][0]=1;
            dp[0][1]=0;
        }
        else{
            dp[0][0]=0;
            dp[0][1]=0;
        }
        for(int i=1;i<n;i++){
            if(s[i]!='0'){
                dp[i][0]=dp[i-1][0]+dp[i-1][1];
            }
            else{
                dp[i][0]=0;
            }
            if(s[i-1]!='0'){
                int k=(s[i-1]-'0')*10+(s[i]-'0');
                if(k>=1 and k<=26)
                    dp[i][1]=dp[i-1][0];
                else
                    dp[i][1]=0;
            }
            else{
                dp[i][1]=0;
            }
        }
        return dp[n-1][0]+dp[n-1][1];
        
    }
};