/*
int dp[n][2];
dp[i][0] means length of subsq where i is at lower position
dp[i][1] means lenght of subsq where i is at higher position
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& v) {        int n=v.size();

        vector<vector<int>>dp(n,vector<int>(2,1));
        for(int i=1;i<n;i++){
            int bade=1;
            int chote=1;
            for(int j=0;j<i;j++){
                if(v[j]>v[i]){
                    chote=max(chote,dp[j][1]+1);
                }
                else if(v[j]<v[i]){
                    bade=max(bade,dp[j][0]+1);
                }
            }
            dp[i][0]=chote;
            dp[i][1]=bade;
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};