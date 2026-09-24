//T.C : O(nlog(max_element_digits))
//S.C : O(1)
class Solution {
public:
bool isEqual(int n, int i){
    int sum = 0;
    while(n){
        sum += (n % 10);
        if(sum > i)return false;
        n /= 10;
    }
    return sum == i;
}
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(isEqual(nums[i],i))return i;
        }
        return -1;
    }
};
