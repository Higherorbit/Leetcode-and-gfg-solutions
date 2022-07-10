class Solution {
public:
    const int mxm=1e5+1;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long >diff(mxm,0);
        for(int i=0;i<nums1.size();i++){
            diff[abs(nums1[i]-nums2[i])]++;
        }
        int tot=k1+k2;
        for(int i=mxm-1;i>0;i--){
            int acc=diff[i];
            int mn=min(acc,tot);
            diff[i-1]+=mn;
            diff[i]-=mn;
            tot-=mn;
        }
        long long ans=0;
        for(long long i=0;i<mxm;i++){
            ans+=diff[i]*i*i;
        }
        return ans;
    }
};