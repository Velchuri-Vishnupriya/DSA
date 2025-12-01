//T.C : O(log(sum/n) * batteries size)
//S.C : O(1);
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 0;
        long long high = accumulate(begin(batteries), end(batteries), 0LL)/n;
        long long res = 0LL;
        while(low <= high){//O(log(sum/n) * batteries size)
            long long mid = low + (high - low)/2;
            long long time = 0;
            for(int& b : batteries){
                time += min(b*1LL,mid);
            }
            if(time >= mid*n){
                res = mid;
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
    return res;}
};
