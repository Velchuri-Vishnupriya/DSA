//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
  long long curr = 0 ;
long long max_ele = INT_MIN;
long long min_ele = INT_MAX;
for (auto& it : diff) {
    curr += (long long)it;
    max_ele = max(curr , max_ele);
    min_ele = min(curr , min_ele);
}
// lower <= l <= upper 
// lower <= l + minval and upper >= 1 + maxval 
//l >= lower - minval l <= upper - maxval
long long start = max((long long)lower, (long long)lower - min_ele);
long long end = min((long long)upper, (long long)upper - max_ele);
return (end - start + 1 > 0 ) ?(int) end - start + 1 : 0;

    }
};
