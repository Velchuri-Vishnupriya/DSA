//Recurrsion with memoization
//T.S: O(n*k)
//S.C:O(n*k)
class Solution {
public:
int n;
int solve(vector<int>& nums,int i,int k,vector<vector<int>>& t,int n){
if(k==0) return 0;

if(i>=n) return INT_MAX;

if(t[i][k] != -1){ return t[i][k];}

int take=max(nums[i],solve(nums,i+2,k-1,t,n));

int not_take=solve(nums,i+1,k,t,n);

return t[i][k]=min(take,not_take);
}
    int minCapability(vector<int>& nums, int k) {
  n=nums.size();
 vector<vector<int>> t(n+1,vector<int>(k+1,-1));
 return solve(nums,0,k,t,n);
    }
};

//Using Binary Search
//T.C:O(log(r)*n) --r -> max element
//S.C:O(1)
class Solution {
public:
int n;
bool ispssble(vector<int>& nums,int mid,int k){
    int houses=0;
    for(int i=0;i<n;i++){
        if(nums[i]<=mid){
            houses++;
            i++;
        }
    }
    return houses>=k;
}
    int minCapability(vector<int>& nums, int k) {
        n=nums.size();
int l=*min_element(begin(nums),end(nums));
int r=*max_element(begin(nums),end(nums));
int result=r;
while(l<=r){
    int mid=l+(r-l)/2;
    if(ispssble(nums,mid,k)){
result=mid;
r=mid-1;
    }
    else{
        l=mid+1;
    }
}
    return result;}
};
