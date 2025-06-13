//T.C: O(n*log m) -> m = r - l , n = nums.size()
class Solution {
public:
int n;
int isValid(vector<int>& nums, int mid, int p){
    int i=0;
    int countPairs = 0;
    while(i<n-1){
        if(abs(nums[i+1] - nums[i]) <= mid) {countPairs++;
        i+=2;}
        else i++;
    }
return countPairs;
}
    int minimizeMax(vector<int>& nums, int p) {
n = nums.size();

sort(begin(nums), end(nums));

int l = 0;
int r = nums[n-1] - nums[0];

int result = -1;
while(l<=r){//O(log m)
    int mid = l +(r-l)/2;
int count = isValid(nums, mid, p) ; //O(n)

    if(count >= p){
        result = mid;
        r = mid-1;
    }
    else{
        l=mid+1;
    }
}
    return result;}
};
