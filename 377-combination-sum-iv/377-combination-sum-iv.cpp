class Solution {
public:
    int combinationSum4(vector<int>& v, int sum) {
            #define int __int128_t
        int n=v.size();
        sort(v.begin(),v.end());
        vector<int>dp(sum+1,0);
        dp[0]=1;
        for(int s=1;s<=sum;s++){
            for(auto i:v){
                if(i<=s){
                    dp[s]+=dp[s-i];
                }
                else{
                    break;
                }
            }
        }
        #undef int
        return dp[sum];
    }
};