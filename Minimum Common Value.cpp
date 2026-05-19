//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        for(int i=0; i<n; i++){
            int target = nums1[i];
            auto itr = binary_search(nums2.begin(), nums2.end(), target);
            if(itr != false)return target;
        }

    return -1;
    }
};
