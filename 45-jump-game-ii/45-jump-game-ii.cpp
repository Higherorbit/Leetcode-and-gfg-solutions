class Solution {
public:
    int n;
    vector<int>dp;
    int dfs(vector<int> &arr, int ind){
        if(ind==n-1){
            return 0;
        }
        if(ind>=n){
            return INT_MAX-1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int ans=INT_MAX-1;
        for(int j=1;j<=arr[ind];j++){
            ans=min(ans,1+dfs(arr,ind+j));
        }
        return dp[ind]=ans;
    }
    int jump(vector<int>& arr) {
        n=arr.size();
        dp.resize(n,-1);
        return dfs(arr,0);
        // int dp[n+1];
        // for(int i=0;i<=n;i++){
        //     dp[i]=INT_MAX-1;
        // }
        // dp[0]=0;
        // // dp[1]=0;
        // for(int i=1;i<=n;i++){
        //     for(int j=i-1;j>=0;j--){
        //         if(arr[j]+j>=i){
        //             dp[i]=min(dp[i],1+dp[j]);
        //         }
        //     }
        // }
        // return dp[n-1];
    }
};