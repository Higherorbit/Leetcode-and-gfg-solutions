class Solution {
public:
    bool search(int x){
        int l=0;
        int r=x;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(mid*mid>x){
                r=mid-1;
            }
            else if(mid*mid<x){
                l=mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
    bool judgeSquareSum(int c) {
        for(long long a=0;a*a<=c;a++){
            if(search(c-a*a)){
                return true;                
            }
        }
        return false;
    }
};