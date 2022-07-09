class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        vector<int>ans;
        int n=v.size();
        multiset<int>s;
        int cnt=0;
        for(int i=0;i<n;i++){
            s.insert(v[i]);
            cnt++;
            if(cnt==k){
                ans.push_back(*s.rbegin());
                cnt--;
                s.erase(s.find(v[i-k+1]));
            }
        }
        return ans;
    }
};