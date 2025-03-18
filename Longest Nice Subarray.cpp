//Approach-1
//T.C: O(n^2)
//S.C: O(1)

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n =nums.size();
int result=0;
for(int i=0;i<n;i++){
   int mask=0;
    for(int j=i;j<n;j++){
        if((mask & nums[j])!=0) break;
        result=max(result,j-i+1);
        mask|=nums[j];
    }
}
    return result;
    
    }
};

//Using Sliding Window 
//S.C: O(1)
//T.C: O(n)

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n =nums.size();
int result=1;
int i=0;
int j=0;
int mask=0;
while(j<n){
    while((mask & nums[j])!=0){
        mask^=nums[i];
        i++;
    }
    mask|=nums[j];
    result=max(result, j-i+1);
    j++;
 }
 return result;
 }
};
