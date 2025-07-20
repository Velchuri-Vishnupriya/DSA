//T.C : O(n*logn)
//S.C: O(N)
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
       int N = nums.size();
       int n = N/3;

       vector<long long> leftArray(N, 0);
       vector<long long> rightArray(N, 0);

       priority_queue<int> maxHeap;
       long long leftSum = 0;
       for(int i=0; i<2*n; i++){//O(2*n*logn)
maxHeap.push(nums[i]); //log(n)
leftSum += nums[i];
if(maxHeap.size() > n){
    int val = maxHeap.top();
    leftSum -= val;
    maxHeap.pop();
}
      leftArray[i] = leftSum;
 }

 priority_queue<int, vector<int>, greater<int>> minHeap;
 long long rightSum = 0;
 for(int i=N-1; i>=n; i--){
minHeap.push(nums[i]);
rightSum += nums[i];

if(minHeap.size() > n){
    rightSum -= minHeap.top();
    minHeap.pop();
}
rightArray[i] = rightSum;
 }
       long long res = LLONG_MAX;
for(int i = n-1; i < 2*n; i++){
    res = min(res, leftArray[i] -  rightArray[i+1]);
}
   return res; }
};
