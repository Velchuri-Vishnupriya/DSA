//Approach-1
//T.S: O(n^2)
//S.C: O(n)
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int> sortednums(begin(nums),end(nums));
        sort(begin(sortednums),end(sortednums));
          bool is_sorted=true;
   for(int r=0;r<n;r++){
 is_sorted =true;
    for(int i=0;i<n;i++){
        if(sortednums[i]!=nums[(i+r)%n]) {is_sorted=false; break;}
    }
    if(is_sorted==true) return true;
   }
        return false;
    }
};

//Approach-2
class Solution {
public:
    bool check(vector<int>& nums) {
     int peak=0;
     int n=nums.size();
     for(int i=0;i<n;i++){
        if(nums[i]>nums[(i+1)%n]) peak++;
     }
     return peak<=1;
    }
};
