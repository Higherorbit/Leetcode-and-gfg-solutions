class Solution {
public:
    set<vector<int>>res;
    void solve(vector<int>&a, int l, int r){
        if(l==r){
            res.insert(a);
        }
        else{
            for(int i=l;i<=r;i++){
                swap(a[i],a[l]);
                solve(a,l+1,r);
                swap(a[i],a[l]);
            }
        }
    }
    void nextPermutation(vector<int>& nums){
        next_permutation(nums.begin(),nums.end());
        return ;
        solve(nums,0,nums.size()-1);
        auto itr=res.begin();
        for(itr;itr!=res.end();itr++){
            if(*itr==nums){
                if(itr==--res.end()){
                    continue;
                }
                nums=*(++itr);
                break;
            }
        }
        if(itr==res.end()){
            nums=*res.begin();
        }
    }
};