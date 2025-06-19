//Approach - 1
//T.C: O(n*logn)
//S.C: class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int partitions = 0;
        int n = nums.size();
        int curr_min = nums[0];
        for(int i=1; i<n; i++){
if(nums[i]-curr_min > k){
    partitions ++;
    curr_min = nums[i];
}
        }
 return partitions + 1;   }
};

//Approach - 2
//T.C : O(n)
//S.C : O(1) --> v[max_value +1] which can be taken as constant space
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> v(maxVal + 1, false);

        for (int num : nums) {
            v[num] = true;
        }

        int partitions = 0;
        int curr_min = -1;
        int i = 0;

        while (i <= maxVal) {
            if (v[i]) {
                if (curr_min == -1) {
                    curr_min = i;
                    partitions++;
                } else if (i - curr_min > k) {
                    curr_min = i;
                    partitions++;
                }
            }
            i++;
        }

        return partitions;
    }
};
