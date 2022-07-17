class Solution {
public:
    int trap(vector<int>& v) {
        int ans=0;
        int n=v.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        int lm=v[0];
        int rm=v[n-1];
        left[0]=v[0];
        right[n-1]=v[n-1];        
        for(int i=1;i<n;i++){
            left[i]=lm=max(lm,v[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=rm=max(rm,v[i]);
        }
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-v[i];
        }
        return ans;
        
    }
};