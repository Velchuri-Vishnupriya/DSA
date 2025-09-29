//Approach - 1
//Using lower_bound
//T.C : O(n^2 * log n)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
   sort(nums.begin(), nums.end());

   int n = nums.size();

   int count = 0;

   for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
auto it = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
int k = it - nums.begin();
count ++ (k - (j + 1));
    }
   }
  return count;  }
};

//Approach - 2
//Using Binary Search
//T.C : O(n^2*log n)
class Solution {
public:
int binarySearch(vector<int>& nums, int l, int r, int target){
    int k = -1;

    while(l <= r){
        int mid = l + (r - l)/2;
        if(nums[mid] < target){
         k = mid;
         l = mid+1;   
        }
        else{
            r = mid - 1;
        }
    }
    return k;
}
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if( n < 3) return 0;

        sort(nums.begin(), nums.end());

        int count = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) continue;
            for(int j = i + 1; j < n; j++){
                int sum = nums[i] + nums[j];

                int k = binarySearch(nums, j+1, n-1, sum);
            if(k != -1){
                count += (k - j);
            }
            }
        }



  return count;  }
};

//Approach - 3
//T.C : O()

