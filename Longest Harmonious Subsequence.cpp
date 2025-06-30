//T.C:O(n*log n)
//S.C:O(1)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        
    sort(begin(nums),end(nums));
int len = 0;
for(int i=1; i<n; i++)
{
    if(nums[i]-nums[i-1]==1){
        int c1 = count(begin(nums),end(nums),nums[i]);
        int c2 = count(begin(nums),end(nums),nums[i-1]);
        len = max(len , c1+c2);
    }
}  
return len;  }
};
