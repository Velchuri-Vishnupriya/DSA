//T.S : O(n)
//S.C: O(n)- we are using here extra space 

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        int i=0;
        
    while(i<n-1){
     if(nums[i]==nums[i+1]){nums[i]=nums[i]*2; nums[i+1]=0;}   
        i++;
    }
for(int i=0;i<n;i++){
    if(nums[i]!=0) result.push_back(nums[i]);
}
for(int i=0;i<n;i++){
    if(nums[i]==0) result.push_back(nums[i]);
}
    return result;}
};

//T.S:O(n)
//S.C: O(1) - Two pass approach

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        
    while(i<n-1){
     if(nums[i]==nums[i+1]){nums[i]=nums[i]*2; nums[i+1]=0;}   
        i++;
    }
    int j=0;
for(int i1=0;i1<n;i1++){
    if(nums[i1]!=0) {nums[j]=nums[i1]; j++;}
    }

    while(j<n){
        nums[j]=0;
        j++;
    }
return nums;
    }
};

//T.S: O(n)
//S.C: O(1) - using one pass approach

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
    while(i<n){
     if(i<n-1 && nums[i]==nums[i+1])
     {nums[i]=nums[i]*2; nums[i+1]=0;}   
if(nums[i] != 0){
     if(i != j)
     {
    swap(nums[i],nums[j]);
        }
         j++;
}
        i++;

    }

return nums;
    }
};
