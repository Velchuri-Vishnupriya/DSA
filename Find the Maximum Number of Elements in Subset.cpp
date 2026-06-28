//T.C : O(n* log log M)
//S.C : O(n)
class Solution {
public:
typedef long long ll;
    int maximumLength(vector<int>& nums) {
        unordered_map<ll, int> mp;

        for(int& num : nums){
            mp[num]++;
        }

        int result = 0;

        if(mp[1] % 2){//odd
        result = mp[1];
        }else{
            result = mp[1] - 1;
        }

        for(auto& [num, _] : mp){
            if(num == 1)continue;

            ll curr = num;
            int len = 0;

            while(mp.count(curr) && mp[curr] > 1){//O(log log M)
            /*2^(2^k) = M
            2^k = log2 M
            k = log log M
            so at max this loop will run O(log log M)*/
                len += 2;
                curr = curr*curr;
            }

            if(mp.count(curr) == 1){
                len += 1;
            }else{
                len -=1;
            }

            result = max(len, result);
        }
    return result;
    }
};
