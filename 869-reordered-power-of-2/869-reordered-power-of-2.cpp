class Solution {
public:
    vector<int>freq(int n){
        vector<int>ans;
        while(n){
            ans.push_back((n%10));
            n/=10;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    bool reorderedPowerOf2(int n) {
        //we will be checking every 2 ki power from 0 to 31 and check if the
        //freq of each digit is same as the freq of the given number
        vector<int>a=freq(n);
        for(int i=0;i<32;i++){
            auto v=freq((1<<i));
            if(v==a){
                return true;
            }
        }
        return false;
    }
};