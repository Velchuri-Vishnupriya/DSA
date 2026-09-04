//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int idx = -1;
        int n = nums.size();
        vector<int> maxEl(n);
        vector<int> minEl(n);

        maxEl[0]=nums[0];
        minEl[n-1]=nums[n-1];

        for(int i=1; i<n; i++){
            maxEl[i] = max(maxEl[i-1], nums[i]);
        }

        for(int j=n-2; j>=0; j--){
            minEl[j]=min(minEl[j+1], nums[j]);
        }

        for(int i=n-1; i>=0; i--){
            if(maxEl[i]-minEl[i] <= k)idx = i;
        }

        return idx;
    }
};
