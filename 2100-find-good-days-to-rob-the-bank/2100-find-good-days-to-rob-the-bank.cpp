class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>inc(n,0);
        vector<int>dec(n,0);
        for(int i=1;i<n;i++){
            if(arr[i]<=arr[i-1]){
                dec[i]=1+dec[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]<=arr[i+1]){
                inc[i]=1+inc[i+1];
            }
        }
        vector<int>ans;
        // for(auto x:dec)cout<<x<<" ";
        // cout<<endl;
        // for(auto x:inc) cout<<x<<" ";
        // cout<<endl;
        for(int i=k;i<=n-k-1;i++){
            if(dec[i]>=k and inc[i]>=k){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};