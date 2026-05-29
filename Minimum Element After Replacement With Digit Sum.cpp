//T.C : O(n)
//S.C : O(1)
class Solution {
public:
int solve(int n){
int sum = 0;
while(n){
    sum += n % 10;
    n /= 10;
}
return sum;
}
    int minElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            nums[i] = solve(nums[i]);
        }
        return *min_element(begin(nums), end(nums));
    }
};
