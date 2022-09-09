class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n=v.size();
        vector<int>ans(n);
        stack<pair<int,int>>s;
        s.push({v[0],0});
        ans[n-1]=-1;
        for(int i=1;i<n;i++){
            int next=v[i];
            while(!s.empty() and s.top().first<next){
                ans[s.top().second]=next;
                s.pop();
            }
            s.push({v[i],i});
        }
        for(int i=0;i<n;i++){
            int next=v[i];
            while(!s.empty() and s.top().first<next){
                ans[s.top().second]=next;
                s.pop();
            }
        }
        
        while(!s.empty()){
            ans[s.top().second]=-1;
            s.pop();
        }
        return ans;
    }
};