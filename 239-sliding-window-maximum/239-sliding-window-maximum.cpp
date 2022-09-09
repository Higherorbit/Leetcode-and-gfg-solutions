class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        int n=v.size();
        vector<int>ans;
        deque<int>dq;
        int i=0;
        for(;i<k;i++){
            while(!dq.empty() and v[dq.back()]<v[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(;i<n;i++){
            ans.push_back(v[dq.front()]);
            while(!dq.empty() and i-dq.front()>=k){
                dq.pop_front();
            }
            while(!dq.empty() and v[dq.back()]<v[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(v[dq.front()]);
        return ans;
        
        
    }
};