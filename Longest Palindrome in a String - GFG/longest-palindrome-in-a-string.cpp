// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        int n=s.size();
        int dp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=false;
                if(i==j){
                    dp[i][j]=true;
                }
            }
        }
        int start=0;
        int max_length=1;
        bool b=true;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                if(b){
                            start=i;
                            b=false;
                        }
                max_length=2;
            }
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i<=n-k;i++){
                int j=i+k-1;
                if(dp[i+1][j-1] and s[i]==s[j]){
                    dp[i][j]=true;
                    if(k>max_length){
                        max_length=k;
                        start=i;
                    }
                }
            }
        }
        string ans="";
        for(int i=start;i<=start+max_length-1;i++){
            ans+=s[i];
        }
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends