// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        long long int a=0;
        long long int b=0;
        if(n==1){
            return arr[0];
        }
        sort(arr,arr+n);
        
        bool bb=true;
        for(int i=0;i<n;i++){
            if(bb){
                a*=10;
                a+=arr[i];
                bb=false;
            }
            else{
                b*=10;
                b+=arr[i];
                bb=true;
            }
        }
        // cout<<a<<" "<<b<<endl;
        return a+b;
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