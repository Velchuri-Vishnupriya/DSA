//Approach - 1
//T.C : O(n)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
      long long result = 0;
    int n = nums.size();
    int i = 0;
    while(i < n){
        int l = 0;
        if(nums[i] == 0){
            while(i < n && nums[i] == 0){
                i++;
                l++;
            }
        }
            else{
                i++;
            }
            result+= (long)l*(l+1)/2;
        
    }
   return result; }
};

//Approach - 2
//T.C : O(n)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
  long long result = 0;
  int n = nums.size();
  int count = 0;
  for(int i=0; i<n; i++){
    if(nums[i]==0){
        count++;
        result+=(long)count;
    }
    else{
        count = 0;
    }
  }
    return result;
}
};
