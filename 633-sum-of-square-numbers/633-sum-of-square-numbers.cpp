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
        for(int i=2;i*i<=c;i++){
            int cnt=0;
            if(c%i==0){
                while(c%i==0){
                    c/=i;
                    cnt++;
                }
            }
            if(i%4==3 and cnt%2==1){
                return false;
            }
        }
        return c%4!=3;
    }
};