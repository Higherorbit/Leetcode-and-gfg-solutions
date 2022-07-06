class Solution {
public:
    int fib(int n) {
        int one=0;
        int two=1;
        int three=0;
        if(n<=1){
            return n;
        }
        for(int i=1;i<=n-1;i++){
            three=one+two;
            one=two;
            two=three;
        }
        return three;
    }
};