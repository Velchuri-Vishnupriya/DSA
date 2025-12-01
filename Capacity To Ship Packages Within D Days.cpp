//T.C : O(n * log(sum(weights)))
//S.C : O(1)
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(begin(weights), end(weights));
        int high = accumulate(begin(weights), end(weights), 0);
        int ans = 0;
        while(low <= high){//O(log sum)
            int mid = low + (high - low)/2;
            int Days = 1;
            int sum = 0;
for(int i = 0; i < weights.size(); i++){//O(n)
if(sum + weights[i] > mid){
    Days ++;
    sum = weights[i];
}else{
    sum += weights[i];
}
}

if(Days <= days){
    ans = mid;
    high = mid - 1;
}else{
    low = mid + 1;
}
        }
    return ans;
    }
};
