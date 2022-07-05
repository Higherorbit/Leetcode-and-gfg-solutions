class Solution {
public:
    int maxConsecutive(int l, int r, vector<int>& v) {
        int ans=0;
        int n=v.size();
        sort(v.begin(),v.end());
        ans=v[0]-l;
        for(int i=1;i<n;i++){
            ans=max(ans,v[i]-v[i-1]-1);
        }
        ans=max(ans,r-v[n-1]);
        return ans;
        
    }
};