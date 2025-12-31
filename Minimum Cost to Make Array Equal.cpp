//T.C : O(n*log (max_element))
class Solution {
public:
typedef long long ll;
    ll costCalculation(vector<int>& nums, vector<int>& cost, int mid){
        ll Cost = 0;
        for(int i = 0; i < nums.size(); i++){
        Cost += 1LL * abs(nums[i] - mid) * cost[i];
        }
        return Cost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
     ll answer = INT_MAX;

     int left = *min_element(nums.begin(), nums.end());
     int right = *max_element(nums.begin(), nums.end());

     while(left <= right){
        int mid = left + (right - left)/2;
       ll curr = costCalculation(nums,cost,mid);
       ll next = costCalculation(nums,cost,mid+1);

       answer = min(curr, next);

       if(curr < next){
        right = mid - 1;
       }else{
        left = mid + 1;
       }
     }

   return answer;
    }
};
