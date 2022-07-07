// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n<=1){
            return 0;
        }else if(arr[0]==0){
            return -1;
        }else{
            int jump=0,position=0,range=0;
            for(int i=0;i<n-1;i++){
                range=max(range,i+arr[i]);
                if(i==position){
                    jump++;
                    if(i>=range){
                        return -1;
                    }
                    position=range;
                }
            }
            return jump;
        }
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends