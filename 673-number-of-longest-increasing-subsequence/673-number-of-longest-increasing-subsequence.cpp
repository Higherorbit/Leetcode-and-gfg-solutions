class Solution {
public:
    int findNumberOfLIS(vector<int>& v) {
        int n=v.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        for(int i=1;i<n;i++){
            for(int j=i;j>=0;j--){
                if(v[j]<v[i]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        cnt[i]=cnt[j];
                    }
                    else if(dp[j]+1==dp[i]){
                        cnt[i]+=cnt[j];
                    }
                }
            }
        }
        int m=*max_element(dp.begin(),dp.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==m){
                ans+=cnt[i];
            }
        }
        return ans;
        
        
    }
};