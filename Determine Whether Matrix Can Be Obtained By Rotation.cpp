//T.C : O(4*m*n) ~ O(m*n)
//S.C : O(1)

class Solution {
public:
int m,n;
void rotate(vector<vector<int>>& mat){
    //transpose
    for(int i =0; i<m; i++){
        for(int j=i+1; j < n; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }

    //reverse
    for(int i = 0; i < m; i++){
        int left = 0;
        int right = n-1;
        while(left < right){
            swap(mat[i][left], mat[i][right]);
            left++;
            right--;
        }
    }
}
bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] != target[i][j])
                    return false;
            }
        }
        return true;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        m = mat.size();
        n = mat[0].size();

        for(int i = 0; i < 4; i++){
            if(isEqual(mat, target)) return true;
            rotate(mat);
        }
        return false;
    }
};
