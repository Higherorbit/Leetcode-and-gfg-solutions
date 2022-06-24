class Solution {
public:
    int maxProfit(int k, vector<int>& v) {
        int n=v.size();
        if(n==1 or k==0){
            return 0;
        }
        vector<int>b(k,0);
        vector<int>s(k,0);
        for(int i=0;i<k;i++){
            b[i]=INT_MIN;
        }
        for(int i=0;i<n;i++){
            b[0]=max(b[0],-v[i]);
            s[0]=max(s[0],b[0]+v[i]);
            for(int j=1;j<k;j++){
                b[j]=max(b[j],s[j-1]-v[i]);
                s[j]=max(s[j],b[j]+v[i]);
            }
        }
        return s[k-1];
        
    }
};