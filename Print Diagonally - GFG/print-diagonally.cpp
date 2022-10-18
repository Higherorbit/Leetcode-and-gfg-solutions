//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>>v){
	    vector<int>ans;
	    for(int j=0;j<n;j++){
	        int r=0;
	        int c=j;
	        while(r<n and c>=0){
	            ans.push_back(v[r++][c--]);
	        }
	    }
	    for(int j=1;j<n;j++){
	        int r=j;
	        int c=n-1;
	        while(r<n and c>=0){
	            ans.push_back(v[r++][c--]);
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends