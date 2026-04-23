//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        vector<long long> arr(n,0);
        for(auto& it : mp){
            vector<int> vec = it.second;
            long long total = 1LL * accumulate(begin(vec), end(vec), 0LL);
            int m = vec.size();
            long long prefixSum = 0;
            for(int idx=0; idx<m; idx++){
                prefixSum += vec[idx];
                long long remainingSum = total - prefixSum;
                long long  sum = 1LL*abs(1LL*vec[idx]*idx - (prefixSum - vec[idx]));
                sum += 1LL*abs(1LL*(m-idx-1)*vec[idx] - remainingSum);
                arr[vec[idx]] = sum;
            }
        }
    return arr;}
};
