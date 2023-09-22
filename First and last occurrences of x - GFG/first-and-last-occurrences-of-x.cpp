//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int A[], int n , int x ){
        
        vector<int>arr(A,A+n);
        int a=lower_bound(arr.begin(),arr.end(),x)==arr.end()?-1:lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int b=upper_bound(arr.begin(),arr.end(),x)==arr.end()?-1:upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        if(arr[n-1]==x){
            b=n-1;
        }
        if(arr[0]==x){
            a=0;
        }
        if(a==-1 or b==-1){
            a=-1,b=-1;
        }
        else{
            if(arr[a]!=x){
                a=-1,b=-1;
            }
        }
        if(b!=-1){
            b--;
        }
        if(arr[n-1]==x){
            b=n-1;
        }
        if(arr[0]==x){
            a=0;
        }
        vector<int>v={a,b};
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends