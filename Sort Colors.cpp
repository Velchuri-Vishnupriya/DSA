//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
   vector<int> nums1 (3,0);
   for(auto& it : nums){
     nums1[it]++;
   }
   int n = nums.size();
   for(int i=0; i<nums.size(); i++){
    if(nums1[0] != 0) {nums[i]=0; nums1[0]=nums1[0]-1;}
    else if (nums1[1] != 0) {nums[i]=1; nums1[1]=nums1[1]-1;}
    else {nums[i]=2; nums1[2]=nums1[2]-1;}
   }
    }
};
