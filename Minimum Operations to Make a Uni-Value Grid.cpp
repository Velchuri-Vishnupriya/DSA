//T.C : O(N*logN) N = m*n
//S.C : O(N)
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x)
    {
    vector<int> vec;
    for(auto& nums : grid){
        for(auto& num : nums){
            vec.push_back(num);
        }
    }
    sort(begin(vec), end(vec));
    int target = vec[vec.size()/2];
    int count = 0;

    for(auto& num : vec){
        if(num % x != target % x)return -1;

        count += abs(target - num)/x;
    }
    return count;
    }
};
