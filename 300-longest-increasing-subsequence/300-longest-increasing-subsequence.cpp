class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        //O(n^2)      
        // at every index we can store the length of long est increeasing subsequence ending at it
        int n=v.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(v[i]>v[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int ans=0;
        for(auto &x:dp){
            ans=max(ans,x);
        }
        return ans;
        
    }
};