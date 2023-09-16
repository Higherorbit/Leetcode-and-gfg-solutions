//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int mod=1e9+7;
class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        if(n==1) return 1;
         if(n==2) return 2;
          if(n==3) return 4;
        long long a=1,b=2,c=4,d;
        for(int i=1;i<=n-3;i++){
            d=a+b+c;
            d%=mod;
            a=b;
            b=c;
            c=d;
            a%=mod;
            b%=mod;
            c%=mod;
        }
        return d;
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends