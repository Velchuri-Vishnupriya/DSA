//T.C : O(n.k) ~ O(n)
//S.C : O(k) ~ O(1)

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> result(k, 0);
        vector<long long> prevCount(k, 0);

        for(int i = 0; i < n; i++){ // O(n)

            // index i par end hone wale sare subarrays
            vector<long long> currCount(k, 0);

            int currentElementRemainder = nums[i] % k;
            currCount[currentElementRemainder]++;

            for(int oldRem = 0; oldRem <= k - 1; oldRem++){ // O(k)

                int newRemain = (long long)oldRem * nums[i] % k;

                currCount[newRemain] += prevCount[oldRem];
            }

            prevCount = std::move(currCount);

            for(int x = 0; x < k; x++){ // O(k)
                result[x] += prevCount[x];
            }
        }

        return result;
    }
};
