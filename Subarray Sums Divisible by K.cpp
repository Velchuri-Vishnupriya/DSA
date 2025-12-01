//BRUTE FORCE
//T.C : O(n*n) TLE
//S.C : O(1)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
int n = nums.size();
for(int i = 0; i < n; i++){
    int sum = nums[i];
    for(int j = i+1; j < n; j++){
        if(sum % k == 0) count++;
        sum += nums[j];
    }
    sum % k == 0 ? count++ : count += 0;
}
        
   return count; }
};

//Optimal
//T.C : O(n) 
//S.C : O(n)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;

int n = nums.size();

unordered_map<int,int> mp; //rem,freq

long long sum = 0;

mp[0] = 1;

for(int  i = 0; i < n; i++){
sum += 1LL * nums[i];

int rem = (sum % k + k) % k;

count += mp[rem];

mp[rem]++;
}

   return count; }
};
