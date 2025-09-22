//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& it:nums){
            mp[it]++;
        }

        int count = 0;
        int max_freq = INT_MIN;

        for(auto& it: mp){
            if(it.second > max_freq){
                max_freq = it.second;
                count = 1;
            }
            else if(it.second == max_freq) count++;
        }
    return count*max_freq;}
};
