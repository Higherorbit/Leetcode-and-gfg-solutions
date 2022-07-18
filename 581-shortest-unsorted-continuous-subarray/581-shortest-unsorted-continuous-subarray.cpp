class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l=-1;
        int r=-1;
        bool firstTime=true;
        int n=nums.size();
        vector<int> check(nums);
        sort(check.begin(),check.end());
        for(int i=0;i<n;i++){
            if(nums[i]!=check[i]){
                if(firstTime){
                    l=i;
                    firstTime=false;
                }
                else{
                    r=i;
                }
            }
        }
        if(l==-1)
            return 0;
        if(r==-1)
            return 1;
        return r-l+1;
    }
};