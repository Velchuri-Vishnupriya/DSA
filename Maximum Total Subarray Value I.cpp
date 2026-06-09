//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
  long long maxVal = (long long)*max_element(begin(nums), end(nums));
  long long minVal = (long long)*min_element(begin(nums), end(nums));

  return (maxVal - minVal)*(long long)k;
    }
};
