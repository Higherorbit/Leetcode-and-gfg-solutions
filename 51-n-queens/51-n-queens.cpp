class Solution {
public:
    vector<vector<string>>res;
    bool isValid(vector<string>&board,int row, int col){
        // to safe to place queen at row and col
        
        //1. there's a queen right above it
        for(int i=0;i<=row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }        
        //2. there's a queen which left and daigonally above it
        for(int i=row,j=col;i>=0 and j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }       
        
        //3. right and daigonally above
        for(int i=row,j=col;i>=0 and j<board.size();i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        } 
        return true;
    }
    void dfs(vector<string>&board,int row){
        //base case
        if(row==board.size()){
            res.push_back(board);
            return ;
        }
        //main code
        for(int j=0;j<board.size();j++){
            if(isValid(board,row,j)){
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