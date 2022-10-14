//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n){
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        sort(a,a+n);
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(mp[a[i]]){
                int f1=mp[a[i]];
                int f2=mp[a[i]-1];
                if(f1>=f2){
                    ans+=f1*a[i];
                    mp[a[i]-1]=0;
                }
                else{
                    ans+=f1*a[i];
                    mp[a[i]-1]-=mp[a[i]];
                }
                // cout<<ans<<endl;
                mp[a[i]]=0;
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends