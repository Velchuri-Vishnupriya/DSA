//T.C : O(k * n/k) ~ O(n)
typedef long long ll;
class Solution {
public:
    ll maxSubarraySum(vector<int>& nums, int k) {       
     int n = nums.size();

     vector<ll> prefSum(n);
     prefSum[0] = nums[0];

     for(int i = 1; i < n; i++){
        prefSum[i] = prefSum[i-1] + nums[i];
     }

     ll result = LLONG_MIN;

     for(int start = 0; start < k; start++){
        ll currSum = 0;

        int i = start;

        while(i < n && i + k -1 < n){
            int j = i + k -1;

            ll subSum = (prefSum[j]) - ((i > 0) ? prefSum[i-1] : 0);

            currSum = max(subSum, currSum + subSum);

            result = max(result, currSum);

            i += k;
        }
     }

    return result;}
};
