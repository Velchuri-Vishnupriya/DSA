//T.C:O(n*2^n)
//S.C:O(n*2^n)
class Solution {
public:
vector<vector<int>> result;
void solve(int i,vector<int>&nums,vector<int>&temp){
    if(i>=nums.size()){
        result.push_back(temp);
        return;
    }
    //take
    temp.push_back(nums[i]);
    solve(i+1,nums,temp);
    //not take
    temp.pop_back();
    solve(i+1,nums,temp);

}
    int subsetXORSum(vector<int>& nums) {
      vector<int> temp;
      solve(0,nums,temp);
      int res=0;
    for(auto& v:result)
    {int curres=0;
        for(auto&v1:v){
            curres=(curres^v1);
        }
        res+=curres;
    }
    return res;}
};

//T.C:O(2^n)
//S.C:O(n)
class Solution {
public:
void solve(int i,vector<int>&nums,vector<int>&temp,int& resultsum){
    if(i>=nums.size()){
      int curres=0;
      for(int i=0;i<temp.size();i++){
curres^=temp[i];
      }
      resultsum+=curres;
        return;
    }
    //take
    temp.push_back(nums[i]);
    solve(i+1,nums,temp,resultsum);
    //not take
    temp.pop_back();
    solve(i+1,nums,temp,resultsum);

}

//T.C:O(n)
//S.C:O(1)
//Using Bitwise op
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
     int res=0;
     for(int i=0;i<nums.size();i++){
        res|=nums[i];
     }
     int n=nums.size();
     return res<<(n-1);
    }
};
    int subsetXORSum(vector<int>& nums) {
      vector<int> temp;
      int resultsum=0;
      solve(0,nums,temp,resultsum);
  return resultsum;
    }
};
