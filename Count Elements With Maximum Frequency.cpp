//2 - Pass Approach
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

//1 - Pass Approach
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> vec(101);
        int maxfreq = 0;
        int total = 0;
        for(auto& it : nums){
            int freq = ++vec[it];
            if(freq > maxfreq){
                maxfreq = freq;
                total = freq;
            }else if(freq == maxfreq){
                total += freq;
            }
        }
        return total;}
};
