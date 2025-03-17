//5 Approaches

//unordered_map
class Solution {
public:
    bool divideArray(vector<int>& nums) {
     int n=nums.size();
     int div=n/2;
     unordered_map<int,int> mp;
     for(int num:nums){
        mp[num]++;
     }
     int pairs=0;
     for(auto i: mp){
        if(i.second%2!=0) return false;
        else pairs+=(i.second)/2;
     }
     return pairs==div;
    }
};

//Unordered_set
class Solution {
public:
    bool divideArray(vector<int>& nums) {
    unordered_set <int> s;
    for(int num: nums){
        if(s.count(num)) s.erase(num);
        else s.insert(num);

    }
   return s.empty(); }
};

//Using Vecctor
class Solution {
public:
    bool divideArray(vector<int>& nums) {
   vector<bool> vec (501,true);
   for(int num:nums){
    vec[num]=!vec[num];
   }
   for(bool val:vec){
    if(!val) return false;
   }
   return true;
    }
};

//using Sort
class Solution {
public:
    bool divideArray(vector<int>& nums) {
 int n=nums.size();
 sort(begin(nums),end(nums));
 for(int i=1;i<n;i+=2){
    if(nums[i]!=nums[i-1]) return false;
 }
   return true;
    }
};

//Using and xor
class Solution {
public:
    bool divideArray(vector<int>& nums) {
 int n=nums.size();
 sort(begin(nums),end(nums));
 for(int i=1;i<n;i+=2)
 {
    if((nums[i]^nums[i-1]) !=0) {return false;}
   }
    return true;}
};
