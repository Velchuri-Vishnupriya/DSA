//T.C : O(n*log n)
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {sort(begin(nums) , end(nums));
    int n = nums.size();
    vector<vector<int>> result;
    for(int i=0; i<n; i+=3){//O(n/3)
        int diff;
        vector<int> v;
        for(int j = i ; j < i + 3; j++) //O(3)
{v.push_back(nums[j]);
        }
        if(abs(v[1] - v[0])> k) return {};
        if(abs(v[1]-v[2]) > k) return {};
        if(abs(v[2]-v[0]) > k) return {};
    result.push_back(v); }
       return result;
    }
};
