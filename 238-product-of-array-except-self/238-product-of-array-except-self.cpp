class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n);
        long long pre=nums[0];
        v[0]=1;
        for(int i=1;i<=n-1;i++){
            v[i]=pre;
            pre*=nums[i];
        }
        long long post=nums[n-1];
        for(int i=n-2;i>=0;i--){
            v[i]*=post;
            post*=nums[i];
        }
        return v;
    }
};