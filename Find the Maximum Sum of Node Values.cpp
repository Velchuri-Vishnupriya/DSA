//Approach - 1
//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edge)
    {
        int count = 0 ;
        long long sum = 0;
        long long loss = LLONG_MAX;
        for(auto& it: nums){
            int num = it ^ k;
            if(num > it) {count++; sum+=num;}
            else sum += it;
            loss =min(loss , (long long)abs(num-it));
        }
    if(count %2 !=0) {
   return sum - loss ; }
else return sum;
    }
};
