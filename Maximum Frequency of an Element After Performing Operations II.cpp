//T.C : O(n*log n)
//S.C : O(n)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(nums.begin(), nums.end()) + k;
        map<int, int> diff; 
        unordered_map<int, int> freq;

        // Build frequency and range difference map
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            int l = max(nums[i] - k, 0);
            int r = min(nums[i] + k, maxVal);

            diff[l]++;
            diff[r + 1]--;
            diff[nums[i]] += 0; // ensure target keys exist
        }

        int result = 1;
        int cumSum = 0;

        for (auto it = diff.begin(); it != diff.end(); it++) {
            cumSum += it->second;  // cumulative sum
            int target = it->first;

            int targetFreq = freq[target];
            int need = cumSum - targetFreq;  
            int maxPossibleFreq = min(need, numOperations);

            result = max(result, targetFreq + maxPossibleFreq);
        }

        return result;
    }
};
