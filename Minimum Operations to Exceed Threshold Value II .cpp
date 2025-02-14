//Using Heap
class Solution {
public:
    static int minOperations(vector<int>& nums, int k) {
long  op=0;
int n=nums.size();

priority_queue<long long, vector<long long>, greater<long long>> minheap;

for(long long i:nums)
{
  minheap.push(i);
}
while(minheap.size()>=2)
{
    long long x=minheap.top();
    if(x>=k) return op;
    minheap.pop();
    long long  y=minheap.top();
    minheap.pop();
    op++;
    long long val=x*2+y;
    minheap.push(val);
}

   return op; }
};
