//Approach - 1
//T.C:O(n*log n)
//S.C:O(1)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        
    sort(begin(nums),end(nums));
int len = 0;
for(int i=1; i<n; i++)
{
    if(nums[i]-nums[i-1]==1){
        int c1 = count(begin(nums),end(nums),nums[i]);
        int c2 = count(begin(nums),end(nums),nums[i-1]);
        len = max(len , c1+c2);
    }
}  
return len;  }
};

//Approach - 2
//T.C:O(n)
//S.C:O(n)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int len  = 0;
        unordered_map<int,int> mp;
        for(auto& num:nums){
            mp[num]++;
        }
        for(auto& num:nums){
            int minele = num;
            int maxele = num+1;
            
            if(mp.count(maxele)){
                len = max(len , (mp[minele]+ mp[maxele]));
            }
        }
return len;  }
};
