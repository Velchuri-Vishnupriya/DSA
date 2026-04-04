//T.C : O(rows*cols)
//S.C : O(rows*cols)
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1)return encodedText;
        int len = encodedText.length();
        int cols = len/rows;
        vector<vector<char>>grid (rows, vector<char>(cols,' '));
        
        int i=0;
        int j=0;
        for(auto& ch : encodedText){
            if(i<rows && j<cols){
                grid[i][j] = ch;
            }
            j++;
            if(j == cols){
                j=0;
                i++;
            }
        }
        string originalText  = "";
        for(int j=0; j<cols; j++){//diagonal traversal max at once only we visit every cell so O(rows*cols)
            
                int col = j;
                int row = 0;
                while(row < rows && col <cols){
                    char ch = grid[row][col];
                    originalText += ch;
                    row = row + 1;
                    col = col + 1;
                }
        
        }
        //removing trailing spaces
        while(!originalText.empty() && originalText.back() == ' '){
            originalText.pop_back();
        }
    return originalText;
    }
};
