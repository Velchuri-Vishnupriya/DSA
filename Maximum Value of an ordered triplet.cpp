//Brute Force
//T.C: O(n^3)
//S.C: O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long res=0;
        for(int i=0;i<=n-1-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
res=max(res,(long(nums[i] - nums[j]) * nums[k]));
                }
            }
        }
    return res >=0 ? res:0;}
};

//T.C:O(n)
//S.C:O(n)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
      long long res=0;
vector<int>leftmaxi(n);
vector<int> rightmaxi(n);
for(int j=1;j<n;j++){
    leftmaxi[j]=max(leftmaxi[j-1],nums[j-1]);
}
for(int j=n-2;j>=0;j--){
    rightmaxi[j]=max(rightmaxi[j+1],nums[j+1]);
}

for(int j=1;j<n;j++){
    res=max(res,(long long)(leftmaxi[j]-nums[j])*rightmaxi[j]);
}
    return res >=0 ? res:0;}
};

//T.C:O(n)
//S.C:O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        //n-1-2
        int n=nums.size();
      long long res=0;
   long long maxdif=0;
   long long maxi=0;
   for(int k=0;k<n;k++){
    res=max(res,maxdif*nums[k]);
    maxdif=max(maxdif,maxi-nums[k]);
    maxi=max(maxi,(long long)nums[k]);
   }
    return res >=0 ? res:0;}
};
