//T.C : O(logn)
//S.C : O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        //S1:
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] > nums.back())low = mid + 1;
            else high = mid;
        }

        int low1 = low;
        int high1 = low-1;

        low = 0; high = n-1;

        //S2:
        while(low1 <= high){
            int mid = low1 + (high - low1)/2;
            if(nums[mid] == target)return mid;
            else if(nums[mid] > target) high = mid-1;
            else low1 = mid+1;
        }

        //S3:
        while(low <= high1){
            int mid = low + (high1 - low)/2;
            if(nums[mid] == target)return mid;
            else if(nums[mid] > target) high1 = mid-1;
            else low = mid+1;
        }

        return -1;
    }
};
