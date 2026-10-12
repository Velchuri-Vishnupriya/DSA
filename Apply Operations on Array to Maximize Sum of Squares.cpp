//T.C : O(n+k)
//S.C : O(32)~O(1)
class Solution {
public:
int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32,0);

        for(int &num : nums){//O(n)
            for(int b=0; b<32; b++){//O(32)
                if(num & (1 << b)){
                    count[b]++;
                }
            }
        }

        long long result = 0;

        while(k--){//O(k)
            long long curr = 0;
            for(int b=0; b<32; b++){//O(32)
                if(count[b] > 0){
                    curr = curr | (1 << b);
                    count[b]--;
                }
            }
            result = (result + curr*curr) % MOD;
        }
    return result;
    }
};
