//T.C : O(n)
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int res = INT_MIN;
        int idx = -1;
        int i=-1;
        for(auto& it: dimensions){
            i++;
            int diagonal_length = (it[0]*it[0])+(it[1]*it[1]);
            if(res < diagonal_length){
                res = diagonal_length;
                idx = i;
            }
            else if(res == diagonal_length){ 
               
                if(it[0]*it[1] > dimensions[idx][0]*dimensions[idx][1]){
                    idx = i;
                }
            }
        }
       
        return dimensions[idx][0]*dimensions[idx][1];
    }
};
