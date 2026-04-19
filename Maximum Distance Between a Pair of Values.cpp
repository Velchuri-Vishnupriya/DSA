//Approach - 1 : TLE
//T.C : O(n*logm) 
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
       //decreasing
       //to get maximum distance we shd choose j such that it is far from i we can apply binary search
       int res = INT_MIN;
       for(int i = 0; i < nums1.size(); i++){
        int l = i;
        int r = nums2.size()-1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(mid >= i && nums2[mid] >= nums1[i]){
                res = max(res, mid - i);
                l++;
            }else{
                r--;
            }
        }
       }
   return res == INT_MIN ? 0 : res;
    }
};

//Approach - 2 
//T.C : O(n+m)
//s.C : O(1)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {int n = nums1.size();
    int m = nums2.size();
int i = 0 ;
int j = 0;
int res = 0;
    while(i < n && j < m){
        if(nums1[i] <= nums2[j]){
            res = max(res, j-i);
            j++;
        }else{
            i++;
        }
    }
    return res;}
};
