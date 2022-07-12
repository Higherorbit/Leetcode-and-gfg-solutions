// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &v, int r, int c){
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mini=min(mini,v[i][j]);
                maxi=max(maxi,v[i][j]);
            }
        }
        int reqCnt=(r*c+1)/2;
        while(mini<maxi){
            int mid=mini+(maxi-mini)/2;
            int cnt=0;
            for(int i=0;i<r;i++){
                cnt+=upper_bound(v[i].begin(),v[i].end(),mid)-v[i].begin();
            }
            if(cnt<reqCnt){
                mini=mid+1;
            }
            else{
                maxi=mid;
            }
        }
        return mini;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends