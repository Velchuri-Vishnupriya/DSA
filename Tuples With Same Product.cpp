//T.C : O(n^2)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        int result=0;
   unordered_map<int,int> mp ;//prdt,count
   for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
mp[nums[i]*nums[j]]++;
    }
   }
   for(auto& it:mp){
  int i=it.second;
    if(i>=2) result+=((i*(i-1))/2)*8; //combinations formula ncr
   } 
   return result;
    }
};

