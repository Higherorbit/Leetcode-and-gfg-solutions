class Solution {
public:
    int findLengthOfLCIS(vector<int>& v) {
        int ans=0;
        int n=v.size();
        int cnt=1;
        if(n==1)return 1;
        for(int i=1;i<n;i++){
            if(v[i]>v[i-1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};