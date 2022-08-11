class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0;
        int j=0;
        for(auto &x:moves){
            if(x=='U'){
                i--;
            }
            else if(x=='D'){
                i++;
            }
            else if(x=='L'){
                j--;
            }
            else{
                j++;
            }
        }
        return (i==0 and j==0);
    }
};