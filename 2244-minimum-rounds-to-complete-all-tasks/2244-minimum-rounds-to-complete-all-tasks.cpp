class Solution {
public:
    int N=100005;
    int minimumRounds(vector<int>& tasks) {
        // dp[n]=dp[n-2]+dp[n-3];
        // dp[0]=0; dp[1]=0; dp[2]=1 dp[3]=1; dp[4]=dp[2]+dp[1]=1 dp[6]=dp[4]+dp[3] dp[7]=dp[5]+dp[4]= 2+ 1
        
        map<int,int>mp;
        int maxi=0;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
            maxi=max(maxi,mp[tasks[i]]);
        }
        vector<int>dp(max(5,maxi+1),0);
        dp[2]=dp[3]=1;
        dp[1]=INT_MAX;
        for(int i=4;i<max(5,maxi+1);i++){
            dp[i]=min(dp[i-2],dp[i-3])+1;
        }
        
        int ans=0;
        for(auto &x:mp){
            //second element is what we need
            if(x.second<2){
                return -1;
            }
            ans+=dp[x.second];
        }
        return ans;
        
    }
};