//T.C : O(n)
//S.C : O(maxSum)
class Solution {
public:
typedef long long ll;
    ll countMajoritySubarrays(vector<int>& nums, int target) {
int n = nums.size();

ll cumSum = 0;
unordered_map<ll, int> mp;

mp[cumSum] += 1;
ll result = 0;
ll validLeftPoints = 0;
for(int j=0; j<n; j++){
    if(nums[j] == target){
        validLeftPoints += 1LL*mp[cumSum];
        cumSum+=1;
    }else{
        cumSum-=1;
        validLeftPoints -= 1LL*mp[cumSum];
    }
    mp[cumSum] += 1;
    result += validLeftPoints;
}
    return result;
    }
};
