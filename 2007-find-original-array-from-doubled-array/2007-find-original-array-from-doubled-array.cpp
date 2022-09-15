class Solution {
public:
    vector<int> findOriginalArray(vector<int>& v) {
        set<int>finalised;
        map<int,int>present;
        int n=v.size();
        vector<int>ans;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            present[v[i]]++;
        }
        for(int i=0;i<n;i++){
            if(present[v[i]]){
                present[v[i]]--;
                if(present[2*v[i]]){
                    present[2*v[i]]--;
                    ans.push_back(v[i]);
                }
                else{
                    return {};
                }
            }
        }
        return ans;
        
    }
};