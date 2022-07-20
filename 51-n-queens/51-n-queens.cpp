class Solution {
public:
    vector<vector<string>>res;
    bool isValid(vector<string>&board, int row, int col){
        // directly above
        for(int i=0;i<=row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }   
        // daigonaly left and above
        for(int i=row,j=col;i>=0 and j>=0; i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        // daigonaly right and above
        for(int i=row,j=col;i>=0 and j<board.size();i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void dfs(vector<string>&board, int row){
        //base case
        if(row==board.size()){
            res.push_back(board);
            return ;
        }
        //main case
        for(int j=0;j<board.size();j++){
            if(isValid(board,row, j)){
                board[row][j]='Q';
                dfs(board,row+1);
                // backtracking
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        dfs(board,0);
        return res;
    }
};