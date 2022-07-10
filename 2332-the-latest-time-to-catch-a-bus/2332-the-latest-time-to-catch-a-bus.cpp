class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int capacity) {
        sort(b.begin(),b.end());
        sort(p.begin(),p.end());
        queue<int> q;
        set<int>s;
        for(int i=0;i<p.size();i++){
            q.push(p[i]);
            s.insert(p[i]);
        }
        int ans=0;
        for(int i=0;i<b.size();i++){
            int cnt=0;
            int curbuss=b[i];
            while(!q.empty() and cnt<capacity and b[i]>=q.front()){
                int t=q.front();
                q.pop();
                cnt++;
                if(!s.count(t-1)){
                    ans=t-1;
                }
            }
            if(cnt<capacity){
                 while(s.find(curbuss)!=s.end()){
                    curbuss--;
                }
                ans=max(ans,curbuss);
            }
        }
        
        return ans;
        
    }
};