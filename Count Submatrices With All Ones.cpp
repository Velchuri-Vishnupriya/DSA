//T.C : O(m*m*n)
//S.C : O(n)
class Solution {
public:
int onedArrayCount(vector<int>& vec){
    int cons = 0;
    int subcount = 0;

    for(int& val: vec){
        if(val == 0){
            cons = 0;
        }else{
            cons++;
        }
        subcount += cons;
    }
return subcount;
}
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int res = 0;
//O(m*m*n)
        for(int startRow =0; startRow < m; startRow++){

            vector<int> vec(n,1);
            for(int endRow = startRow; endRow < m; endRow++){
                for(int col=0; col < n; col++){
                    vec[col] = vec[col] & mat[endRow][col];
                }
                res += onedArrayCount(vec);
            }
        }
    return res;}
};
