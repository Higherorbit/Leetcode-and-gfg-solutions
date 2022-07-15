// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        long long int ans=0;
        if(n==1){
            return arr[0];
        }
        sort(arr,arr+n);
        string s="";
        string t="";
        bool bb=true;
        for(int i=0;i<n;i++){
            if(bb){
                s+=to_string(arr[i]);
                bb=false;
            }
            else{
                t+=to_string(arr[i]);
                bb=true;
            }
        }
        long long a=s[s.size()-1]-'0';
        long long b=t[t.size()-1]-'0';
        // cout<<a<<endl;
        // cout<<b<<endl;
        long long p=10;
        for(int i=s.size()-2;i>=0;i--){
            a+=(s[i]-'0')*p;
            p*=10;
        }
        p=10;
        for(int i=t.size()-2;i>=0;i--){
            b+=(t[i]-'0')*p;
            p*=10;
        }
        // cout<<b<<endl;
        ans=a+b;
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends