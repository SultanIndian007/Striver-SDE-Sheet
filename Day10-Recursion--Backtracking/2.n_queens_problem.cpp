//tc->o(n! * n), sc->O(n) mark row + col diagonal as 1 if hashed already
class Solution {
public:
    void solve(int col, vector<int>&board,vector<vector<string>>&ans, vector<int>&leftRow, vector<int>upperDiag, vector<int>lowerDiag, int n){

        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++){
            if(leftRow[row] == 0 && lowerDiag[row+col] == 0 && upperDiag[n-1+col-row] ==0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiag[row+col] = 1;
                upperDiag[row+col] = 1;
                
                solve(col+1,board,ans,leftRow,upperDiag,lowerDiag,n);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiag[row+col] = 0;
                upperDiag[row+col] = 0;                
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>>ans;

        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        vector<int> leftRow(n,0), upperDiag(2*n-1,0), lowerDiag(2*n-1,0);
        solve(0,board,ans,leftRow,upperDiag,lowerDiag,n);
        return ans;
    }
};


//TC-> n! * n, sc->O(n^2) has an extra O(n) space so we do hashing
class Solution {
public:
    bool isSafe1(int row, int col, vector<string>board, int n){
        int duprow = row, dupcol = col;

        while(row >= 0 && col >=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }
        col = dupcol;
        row = duprow;
        while(col>=0){
            if(board[row][col] =='Q') return false;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe1(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};