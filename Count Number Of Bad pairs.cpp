//Approach-1 
//T.C : O(N^2)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       long long result=0;
       int n=nums.size();
       for(int j=1;j<n;j++){
        for(int i=0;i<j;i++){
            if(j-i != nums[j]-nums[i]) result++;
        }
       } 
       return result;
    }
};
//Approach-2
//T.C & S.C: O(n)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       long long n=nums.size();
       unordered_map<long long,long long> mp;
           long long goodpairs=0;
       long long totalpairs=(n*(n-1))/2;
       for(int j=0;j<n;j++){
   int val=nums[j]-j;
    if(mp.find(val)!=mp.end()){
        goodpairs+=mp[val];
        }
    mp[val]++;
       }
return totalpairs-goodpairs;
    }
};

//Approach-3
//T.C :O(n)
//S.C; O(n)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
   long long result=0;
   int n=nums.size();
   for(int i=0;i<n;i++){
    nums[i]=nums[i]-i;
   } 
   unordered_map<int,int> mp;
   mp[nums[0]]=1;
   for(int j=1;j<n;j++){
    int countofJ=mp[nums[j]];
    //j=total pairs frpm 0 to j
    result+=j-countofJ;
    mp[nums[j]]++;
   }
   return result;}
};
