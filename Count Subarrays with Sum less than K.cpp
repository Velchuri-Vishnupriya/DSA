//Sliding Window 
//T.C: O(n)
//S.C: O(n)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
    int i=0; int j=0;
    long long sum=0;
    long long score=0;
    long long  result=0;
    while(j<nums.size()){
        sum+=nums[j];
score=sum*(j-i+1);
if(score<k) result+=(j-i+1);
else{
    while(i<nums.size() && score>=k){
        sum-=nums[i];
        i++;
        score=sum*(j-i+1);
    }
  result+=(j-i+1);
}
     j++; }
    return result;}
};
