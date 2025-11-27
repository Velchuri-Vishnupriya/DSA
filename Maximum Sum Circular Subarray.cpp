//Approach - 1 - TLE
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int kadens(vector<int>& nums){
        int currSum = 0;
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            currSum = max(nums[i], nums[i] + currSum);
            res = max(res, currSum);
        }
        return res;
    }

    vector<int> leftRotate(vector<int>& nums1){
        int n = nums1.size();
        vector<int> nums2(n);
        for(int i = 0; i < n - 1; i++){
            nums2[i] = nums1[i + 1];
        }
        nums2[n - 1] = nums1[0];
        return nums2;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int result = kadens(nums);   // include original array
        vector<int> rot = nums;

        while (true) {
            rot = leftRotate(rot);
            if (rot == nums) break;  // full rotation done

            result = max(result, kadens(rot));
        }

        return result;
    }
};

//Approach - 2
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
int kadanesMax(vector<int>& nums, int n){
    int sum = nums[0];
    int maxSum = nums[0];

    for(int i = 1; i < n; i++){
        sum = max(sum + nums[i], nums[i]);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int kadensMin(vector<int>& nums, int n){
    int sum = nums[0];
    int minSum = nums[0];

    for(int i = 1; i < n; i++){
        sum = min(sum + nums[i], nums[i]);
        minSum = min(minSum, sum);
    }
    return minSum;
}

    int maxSubarraySumCircular(vector<int>& nums) {
      int n = nums.size();

      //pt1
      int SUM = accumulate(begin(nums), end(nums), 0);

      //pt2
      int minSum = kadensMin(nums, n);

      //pt3
      int maxSum = kadanesMax(nums, n); //case - 1;

      //pt4
      int circular_sum = SUM - minSum;

      if(maxSum > 0){
        return max(maxSum, circular_sum);
      }

        return maxSum;
    }
};
