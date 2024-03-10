class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1;
        set<int>ans;
        for(int i=0;i<nums1.size();i++){
            s1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            if(s1.count(nums2[i])){
                ans.insert(nums2[i]);
            }
        }
        vector<int>res;
        for(auto x:ans) res.push_back(x);
        return res;
    }
    
};