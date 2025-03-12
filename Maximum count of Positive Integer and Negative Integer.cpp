class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0;
        int neg=0;
        for(int i=0;i<nums.size();i++){
if(nums[i]<0) neg++;
else if(nums[i]>0) pos++;
        }
        return max(pos,neg);
    }
};

//Using C++ STL Library Function - count_if
class Solution {
public:
    int maximumCount(vector<int>& nums) {
       auto P =[] (int num){return num>0;};
       auto N=[] (int num){return num<0;};
       int CP= count_if(begin(nums),end(nums),P);
       int CN= count_if(begin(nums),end(nums),N);
       return max(CP,CN);
    }
};

//Using Binary Search (Lower Bound)
// The array has to in a SORTED MANNER
// Lower_Bound is used to find the first occurance where value is greater thanor equal to the element in the range
class Solution {
public:
    int maximumCount(vector<int>& nums) {
       int n=nums.size();
       int firstP=lower_bound(begin(nums),end(nums),1)-begin(nums);
       int lastN=lower_bound(begin(nums),end(nums),0)-begin(nums);
       return max(n-firstP,lastN);
    }
};
