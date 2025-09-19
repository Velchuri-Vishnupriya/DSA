//T.C : O(n) at max n value = number of rows + 1(col)
//S.C : O(rows*26) ~ O(rows)
class Spreadsheet {
public:
vector<vector<int>> vec;
    Spreadsheet(int rows) {
        vec.assign(rows+1, vector<int>(26,0)); //O(rows)
    }
    
    void setCell(string cell, int value) {//O(1)
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        vec[row][col]=value;
    }
    
    void resetCell(string cell) {//O(1)
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        vec[row][col]=0;
    }
    
    bool isNumericString(string s){//O(n)
        for(auto& ch : s){
            if(!isdigit(ch)) return false;
        }
        return true;
    }
  int getValue(string formula) {
    int pos = formula.find('+');
        string f1 = formula.substr(1, pos - 1);
        string f2 = formula.substr(pos + 1);
        
        int val1, val2;
      
        if(isNumericString(f1)) {//O(n)
            val1 = stoi(f1);
        } else {
            int col = f1[0] - 'A';
            int row = stoi(f1.substr(1));
            val1 = vec[row][col];
        }
        
        if(isNumericString(f2)) {//O(n)
            val2 = stoi(f2);
        } else {
            int col2 = f2[0] - 'A';
            int row2 = stoi(f2.substr(1));
            val2 = vec[row2][col2];
        }
        
        return val1 + val2;
    }
};
