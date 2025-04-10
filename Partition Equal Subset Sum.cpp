//Recurrsion + Memo
//T.C: O(n*x)
//S.C: O(n*x)
class Solution {
public:
 int n;
 int t[201][20001];
bool solve(vector<int>& nums,int i,int x){
    if(x==0) return true;

    if(i>=n) return false;

if(t[i][x] !=-1) return t[i][x];
    //take
    bool take=false;
    if(x>=nums[i]){
        take=solve(nums,i+1,x-nums[i]);
    }

//not_take
    bool not_take=solve(nums,i+1,x);

    return t[i][x]=take|| not_take;
}
    bool canPartition(vector<int>& nums) {
      n=nums.size();

     int S=accumulate(begin(nums),end(nums),0);

     if(S%2 !=0){
        return false;
     }
int x=S/2;
memset(t,-1,sizeof(t));
return solve(nums,0,x);
}
};
