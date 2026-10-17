//T.C : O(nlogn * log(maxNum))
//S.C : O(n)
class Solution {
public:
int digitSum(int n){
    int sum = 0;
    while(n){
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> afterSorted(nums);

        auto lambda = [&](int num1, int num2){
            int num1Sum = digitSum(num1);
            int num2Sum = digitSum(num2);

            if(num2Sum != num1Sum)return num1Sum < num2Sum;
            return num1 < num2;
        };

        sort(begin(nums), end(nums), lambda);

        unordered_map<int,int> valToIdx;
        for(int i=0; i<n; i++){
            valToIdx[nums[i]] = i;
        }

        int swap = 0;
        for(int i=0; i<n; i++){
            int expectedVal = afterSorted[i];
            int currVal = nums[i];

            if(expectedVal == currVal)continue;

            int idx = valToIdx[expectedVal];
            nums[i] = expectedVal;
            nums[idx] = currVal;

            valToIdx[expectedVal] = i;
            valToIdx[currVal] = idx;

            swap++;
        }
   return swap; 
   }
};
