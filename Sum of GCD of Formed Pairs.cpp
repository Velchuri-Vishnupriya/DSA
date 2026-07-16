//T.C : O(nlog(max_el) + nlogn)
//S.C : O(n)
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int max_el = INT_MIN;
        int n = nums.size();
        vector<int> prefixGCD(n);
        for(int i=0; i<n; i++){
            max_el = max(max_el, nums[i]);
            prefixGCD[i] = gcd(nums[i], max_el);
        }
        long long sum = 0;
        sort(begin(prefixGCD), end(prefixGCD));
        for(int i=0; i<n/2; i++){
            //n-1-i
            long long pairGCD = 1LL*gcd(prefixGCD[i], prefixGCD[n-1-i]);
            sum += pairGCD;
        }
    return sum;
    }
};
