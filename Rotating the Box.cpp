//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
    int m = boxGrid.size();
    int n = boxGrid[0].size();

    //Apply Gravity
    for(int i=0; i<m; i++){
        int empty = n-1;
        for(int j=n-1; j>=0; j--){
            if(boxGrid[i][j] == '*'){//obstacle
                empty = j-1;
            }
            else if(boxGrid[i][j] == '#'){
                swap(boxGrid[i][j], boxGrid[i][empty]);
                empty--;
            }
        }
    }

    //rotate
    vector<vector<char>>result(n, vector<char>(m));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            result[j][m-1-i] = boxGrid[i][j];
        }
    }
    return result;
    }
};
