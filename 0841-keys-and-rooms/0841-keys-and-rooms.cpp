class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        function<void(int)> dfs=[&](int x){
            if(visited[x]) return ;
            visited[x]=1;
            for(auto i:rooms[x]){
                dfs(i);
            }
        };
        dfs(0);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};