class Solution {
public:
    bool isThree(int n) {
        int cnt=0;
        for(int i=2;i<n;i++){
            if(n%i==0){
                cnt++;
            }
        }
        if(cnt==1){
            return true;
        }
        return false;
    }
};