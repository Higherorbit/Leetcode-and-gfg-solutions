class Solution {
public:
    static bool comp(int x,int y){
        if(__builtin_popcount(x)!=__builtin_popcount(y))
            return __builtin_popcount(x)<=__builtin_popcount(y);
        else
            return x<=y;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> v;
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};