//T.C : O(nlogn + mlogn)
//S.C : O(1)
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& nums2, int d) {
        sort(begin(nums2), end(nums2));//O(nlogn)

        int count  = 0;
        int n = nums2.size();

        for(int i=0; i<arr1.size(); i++){//O(m)
            int j = lower_bound(nums2.begin(), nums2.end(), arr1[i]) - nums2.begin();//O(logn)

            if(j == 0){
                //all ele >= arr1[i]
                count += (nums2[j]-arr1[i]) > d;
            }else if(j >= n){
                //all ele < arr1[i]
                count += (arr1[i] - nums2[n-1]) > d;
            }else{
                count += ((arr1[i] - nums2[j-1]) > d) && ((nums2[j] - arr1[i]) > d); 
            }
        }
    return count;
    }
};
