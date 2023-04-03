class Solution {
public:
    int numRescueBoats(vector<int>& v, int t) {
        int ans=0;
        int n=v.size();
        int l=0,r=n-1;
        sort(v.begin(),v.end());
        while(l<=r){
            int sum=v[l]+v[r];
            ans++;
            if(sum<=t){
                l++;
            }
            r--;
        }
        return ans;
        
    }
};