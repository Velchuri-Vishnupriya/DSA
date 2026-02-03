//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
       
       //Up
       while(i + 1 < n && nums[i] < nums[i+1]) i++;
       if(i == n-1 || i == 0) return false;

       int p = i;

       //down
       while(i + 1 < n && nums[i] > nums[i+1]) i++;
       if(i == p || i == n-1) return false;

       //Up
       while(i + 1 < n && nums[i] < nums[i+1]) i++;
       return i == n-1;

    }
};
