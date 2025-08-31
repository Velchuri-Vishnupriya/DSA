//Classic backtraing problem 
//T.C : O(9^81)
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char d){
        //row nd col check
        for(int i=0; i < 9; i++){
            if(board[row][i] == d || board[i][col] == d) return false;
        }
        //box check
        int start_i = row/3 * 3;
        int start_j = col/3 * 3;
        for(int i = start_i; i < start_i + 3; i++){
            for(int j = start_j; j < start_j + 3; j++){
                if(board[i][j] == d) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    for(char d = '1'; d <= '9'; d++){
                        if(isValid(board,i,j,d)){
                            board[i][j] = d;
                            if(solve(board) == true) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
