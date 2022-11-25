//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#include<bits/stdc++.h>
class Solution{
public:
        vector<long long> find(long long x)
    {
        vector<long long> ans;
        long long c=0;
        
        while(x>0)
        {
            if(x&1)
            {
                c++;
                ans.push_back(c);
            }
            else
                ans.push_back(-1);
                
            x=x>>1;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
    
    long long ncr(long long n,long long r,vector<vector<long long>> &dp)
    {
        if(r==n || r==0)
        return 1;
        
        if(r==n-1 || r==1)
        return n;
        
        if(dp[n][r]==-1)
            dp[n][r]=ncr(n-1,r-1,dp)+ncr(n-1,r,dp);
        
        return dp[n][r];
    }
    
    long long count(long long x) {
        // Code Here
        
        long long ans=0;
        vector<long long> cnt=find(x);
        long long i,n=cnt.size();
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,-1));
        
        for(i=n-1;i>=0;i--)
        {
            if(cnt[i]!=-1 && cnt[i]<n-i)
                ans+=ncr(n-i-1,cnt[i],dp);
        }
        
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends