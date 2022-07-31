class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int i;
        for(i=0;grades.size()>=i*(i+1)/2; i++);
        return i-1;
    }
};