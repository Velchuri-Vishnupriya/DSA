//Recurrsion + Memoization
//T.C : O(n*log n) --> log n for lower_bound since we call the function for every state
//S.C : O(n)
class Solution {
public:
typedef long long ll;
int n;
vector<ll> t;
unordered_map<ll,ll> mp;
ll solve(vector<ll>& nums, int i){
if(i >= n) return 0;

if(t[i] != -1) return t[i];
//skip
ll skip =solve(nums, i+1);

//take
int j = lower_bound(begin(nums)+i+1, end(nums), nums[i] + 3) - begin(nums);
ll take =  nums[i]*mp[nums[i]] + solve(nums, j);

return t[i] = max(skip, take);
}
    ll maximumTotalDamage(vector<int>& power) {
        
        for(int& x : power){
            mp[x]++;
        }

        vector<ll> nums;

        for(auto& it: mp){
            nums.push_back(it.first);
        }

        sort(begin(nums), end(nums));
        n = nums.size();
        t.assign(n+1, -1);
        return solve(nums, 0);
        
         }
};

//Bottom -Up
//T.C : O(n*log n) --> log n for lower_bound since we call the function for every state
//S.C : O(n)
class Solution {
public:
typedef long long ll;
int n;
vector<ll> t;
unordered_map<ll,ll> mp;
    ll maximumTotalDamage(vector<int>& power) {
        
        for(int& x : power){
            mp[x]++;
        }

        vector<ll> nums;

        for(auto& it: mp){
            nums.push_back(it.first);
        }

        sort(begin(nums), end(nums));
        n = nums.size();
        t.assign(n+1, 0);
        
        ll result = 0;

        for(int i = n-1; i >= 0; i--){
            ll skip = t[i+1];
            int j = lower_bound(begin(nums)+i+1,end(nums), nums[i]+ 3) - begin(nums);
            ll take = nums[i]*mp[nums[i]] + ((j < n) ? t[j] : 0);

            t[i] = max(skip, take);
            result = max(result, t[i]);
        }
return result;
         }
};
