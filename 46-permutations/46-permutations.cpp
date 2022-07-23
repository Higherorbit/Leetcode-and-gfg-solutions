class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int>&a, int l, int r){
        if(l==r){
            res.push_back(a);
        }
        else{
            for(int i=l;i<=r;i++){
                swap(a[i],a[l]);
                solve(a,l+1,r);
                swap(a[i],a[l]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums,0,nums.size()-1);
        return res;
    }
};