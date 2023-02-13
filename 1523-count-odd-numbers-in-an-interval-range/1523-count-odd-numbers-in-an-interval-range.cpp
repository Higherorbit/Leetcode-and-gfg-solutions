class Solution {
public:
    int countOdds(int l, int h) {
        int n=h-l+1;
        if(n&1){
            if(l&1 and h&1){
                return n/2+1;
            }
            return n/2;
        }
        else{
            return n/2;
        }
    }
};