//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        int m = mat.size();
        int n = mat[0].size();

        vector<int> rows(m);
        vector<int> cols(n);

        
        //number of ones in row and col
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
          if(mat[i][j] == 1){
            rows[i]++;
            cols[j]++;
          }
            }
        }

        //check for unique 1s
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1)count++;
            }
        }

    return count;
}
};
