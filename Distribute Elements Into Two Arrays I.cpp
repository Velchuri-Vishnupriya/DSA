//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> result;
        vector<int> arr2;
        result.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int n = nums.size();
        for(int i=2; i<n; i++){
            if(result.back() > arr2.back()){//O(1)
                result.push_back(nums[i]);//O(1)
            }else{
                arr2.push_back(nums[i]);//O(1)
            }
        }
        result.insert(result.end(), arr2.begin(), arr2.end());
    return result;}
};
