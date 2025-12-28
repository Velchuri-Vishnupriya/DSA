//Approach - 1
//T.C : O(n * m)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(auto& row : grid){
            for(int i = row.size()-1; i >= 0; i--){
                if(row[i] >= 0)break;
                else count++;
            }
        }
        return count;
    }
};

//Approach - 2
//T.C : O(n*log m)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;

        for (auto& row : grid) {
            int l = 0, r = row.size() - 1;
            int idx = row.size();

            while(l <= r){
                int mid = l + (r - l)/2;
                if(row[mid] < 0){
                    r = mid - 1;
                    idx = mid;
                }else{
                    l = mid + 1;
                }
            }
            count += (row.size()-idx);
        }

        return count;
    }
};
