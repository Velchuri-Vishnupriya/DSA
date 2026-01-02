//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> st;

        for(auto& num : nums){
            if(st.find(num) == st.end()) st.insert(num);
            else return num;
        }

        return nums[0];
    }
};
