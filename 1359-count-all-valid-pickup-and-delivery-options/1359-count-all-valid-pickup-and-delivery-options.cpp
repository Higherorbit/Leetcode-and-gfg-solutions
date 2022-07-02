/*
2n!/2^n
*/
class Solution {
public:
    #define int unsigned long long int
    int countOrders(int n) {
        int ans=1;
        const int mod=1e9+7;
        for(int i=1;i<=2*n;i++){
            ans=ans*i;
            if(i%2==0){
                ans/=2;
            }
            ans%=mod;
        }
        #undef int
        return ans;
    }
};