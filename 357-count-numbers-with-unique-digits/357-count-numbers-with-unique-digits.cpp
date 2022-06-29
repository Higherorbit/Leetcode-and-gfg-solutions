class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int sum = 1, perm = 9, i = 1;
        
        while (i <= n && i <= 10){
            sum += perm;
            perm *= (11-++i);
        }
        
        return sum;
    }
};