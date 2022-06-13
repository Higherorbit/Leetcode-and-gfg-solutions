// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&v){
	    vector<pair<int,int>>p;
	    for(int i=0;i<v.size();i++){
	        p.push_back(make_pair(v[i],i));
	    }
	    sort(p.begin(),p.end());
	    int ans=0;
	    int n=v.size();
	    vector<bool> visited(n,false);
	    for(int i=0;i<v.size();i++){
	        if(p[i].second==i or visited[i]){
	            continue;
	        }
	        int j=i;
	        int cycle_size=0;
	        while(!visited[j]){
	            cycle_size++;
	            visited[j]=true;
	            j=p[j].second;
	        }
	        ans+=cycle_size-1;
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends