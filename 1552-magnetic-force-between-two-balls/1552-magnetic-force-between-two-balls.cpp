class Solution {
public:
    bool good(vector<int>&v, int m, int val){
        int pos=0;
        int k=1;
        for(int i=1;i<v.size();i++){
            if(abs(v[i]-v[pos])>=val){
                k++;
                pos=i;
            }
            if(k==m){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& v, int m) {
        sort(v.begin(),v.end());
        int s=0;
        int e=1;
        while(good(v,m,e)){
            e*=2;
        }
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(good(v,m,mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};