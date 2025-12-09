//T.C : O(n)
//S.C : O(n)
class Solution {
public:
typedef long long ll;
const int M = 1e9+ 7;
    int specialTriplets(vector<int>& nums) {
       int n = nums.size();

       unordered_map<ll,ll> nxtFreq;
       unordered_map<ll,ll> prevFreq;
       int res = 0;

       for(int i = 0; i < n; i++){
        nxtFreq[nums[i]]++;
       }

       for(int i = 0; i < n; i++){
        int jval = nums[i];
        int need = jval*2;
        
        nxtFreq[jval]--;

        if(prevFreq.count(need) && nxtFreq.count(need)){
            res = (res + (prevFreq[need] * nxtFreq[need]) % M) % M;
        }

        prevFreq[jval]++;
       }
    return res % M;
    }
};
