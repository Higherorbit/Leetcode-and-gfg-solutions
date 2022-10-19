//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool dfs(int x,int n, vector<int>adj[], set<int>&s,vector<bool>&v){
        bool b=(s.size()==n);
        for(auto i:adj[x]){
            if(v[i]==0){
                s.insert(i);
                v[i]=1;
                if(dfs(i,n,adj,s,v)){
                    b=true;
                }
                s.erase(i);
                v[i]=0;
            }
        }
        return b;
    }
    bool check(int n,int m,vector<vector<int>> e){
        vector<int>adj[n];
        for(int i=0;i<m;i++){
            //add in adj
            adj[e[i][0]-1].push_back(e[i][1]-1);
            adj[e[i][1]-1].push_back(e[i][0]-1);
        }
        for(int i=0;i<n;i++){
            set<int>s;
            s.insert(i);
            vector<bool>v(n,false);
            v[i]=1;
            if(dfs(i,n,adj,s,v)){
                return true;
            }
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends