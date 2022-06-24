class Solution {
public:
    int maxProfit(vector<int>& v) {
        int fs=0;
        int fb=INT_MIN;
        int sb=INT_MIN;
        int ss=0;
        int n=v.size();
        if(n==1){
            return 0;
        }
        for(int i=0;i<n;i++){
            fb=max(fb,-v[i]);
            fs=max(fs,fb+v[i]);
            sb=max(sb,fs-v[i]);
            ss=max(ss,sb+v[i]);
        }
        return ss;
    }
};