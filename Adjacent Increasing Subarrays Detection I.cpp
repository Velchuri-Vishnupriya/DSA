//T.C: O(n*k)
//S.C: O(1)
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // there must exist at least 2*k elements
        if (n < 2 * k) return false;

        for (int i = 0; i + 2 * k - 1 < n; i++) {//O(n - 2*k + 1)
            int a = i;
            bool Found = true;

            // 1st subarray
            for (int j = a; j < a + k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    Found = false;
                    break;
                }
            }
            if (!Found) continue;

            // 2nd subarray
            for (int j = a + k; j < a + 2 * k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    Found = false;
                    break;
                }
            }

            if (Found) return true;
        }

        return false;
    }
};

//Approach - 2
//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int currlen = 1;
        int prevlen = 0;
        
        
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]) currlen++;
            else{
                prevlen = currlen;
                currlen = 1;
            }
            if(currlen >= 2*k) return true;
            if(min(currlen, prevlen) >= k) return true;
        }
        return false;
    }
};

