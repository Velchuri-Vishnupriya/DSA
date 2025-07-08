 //Binary search
 //T.C : O(log n)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> arr = {-1,-1};

        int l = 0 ;
        int r = nums.size() - 1;

        while(l<=r){
        int mid = l + (r - l)/2;
            if(nums[mid] == target){
                r = mid -1;
                arr[0] = mid;
            }
            else if (nums[mid] > target) r = mid -1;
            else l = mid + 1;
        }
l = 0;
r = nums.size() - 1;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                l = mid + 1;
                arr[1] = mid;
            }
            else if(nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
    return arr;
    }
};
