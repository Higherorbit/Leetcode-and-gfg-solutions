class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v) {
        set<int>s;
        int ans=0;
        int sum=0;
        int i=0;
        int start=0;
        
        while(i<v.size()){
            if(!s.count(v[i])){
                sum+=v[i];
                s.insert(v[i]);
                i++;
            }
            else{
                sum-=v[start];
                s.erase(s.find(v[start]));
                start++;
            }
            // cout<<ans<<endl;
            ans=max(ans,sum);
        }
        return ans;
    }
};