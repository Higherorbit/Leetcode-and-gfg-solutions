class Solution {
public:
    int n;
    int m;
    bool dfs(vector<vector<char>>& board, string word,vector<vector<bool>>&visited, int i, int j,int ind){
        // base case
        if(ind==word.size()){
            return true;
        }
        if(i<0 or j<0 or i>=n or j>=m){
            return false;
        }
        if(visited[i][j] or board[i][j]!=word[ind]){
            return false;
        }
        //main code
        visited[i][j]=true;
        bool ans=dfs(board,word,visited,i-1,j,ind+1)| 
                dfs(board,word,visited,i+1,j,ind+1)|
                dfs(board,word,visited,i,j-1,ind+1)|
                dfs(board,word,visited,i,j+1,ind+1);
        visited[i][j]=false;
        return ans;       
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,visited,i,j,0))
                        return true;
                }
            }
        }
        return false;
    }
};