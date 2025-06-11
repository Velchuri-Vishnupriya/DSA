//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
  int curr = 0 ;
int max_ele = INT_MIN;
int min_ele = INT_MAX;
for (auto& it : diff) {
    curr += it;
    max_ele = max(curr , max_ele);
    min_ele = min(curr , min_ele);
}
// lower <= l <= upper 
// lower <= l + minval and upper >= 1 + maxval 
//l >= lower - minval l <= upper - maxval
int start = max(lower, lower - min_ele);
int end = min(upper, upper - max_ele);
return (end - start + 1 > 0 ) ? end - start + 1 : 0;

    }
};
