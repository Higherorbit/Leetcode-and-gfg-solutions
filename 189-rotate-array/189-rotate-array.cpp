class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto a=nums;
        int n=nums.size();
        int j=0;
        k%=n;
        for(int i=n-k;i<2*n-k;i++){
            a[j++]=nums[i%n];            
        }
        nums=a;
    }
};