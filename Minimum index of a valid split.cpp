//Brute force (using 2 maps)
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
int n=nums.size();
unordered_map<int,int> mp1;
unordered_map<int,int> mp2;
for(int& num: nums){
    mp2[num]++;
}
for(int i=0;i<n;i++){
mp1[nums[i]]++;
mp2[nums[i]]--;
int n1=i+1;
int n2=n-i-1;
if(mp1[nums[i]]*2>n1 && mp2[nums[i]]*2>n2){return i;}
}
  return -1;  }
};

//better approach
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
int n=nums.size();

int maj=-1;
int cnt=0;
for(int i=0;i<n;i++)
{if(cnt==0){
    maj=nums[i];
    cnt++;
}
else if(nums[i]==maj){cnt++;}
else cnt--;}

int majcnt=0;
for(int i=0;i<n;i++){
    if(nums[i] == maj) majcnt++;
}

int count=0;
for(int i=0;i<n;i++){
    if(nums[i]==maj) count++;
    int remcnt=majcnt-count;
    int n1=i+1;
    int n2=n-i-1;
    if(count*2>n1 && remcnt*2>n2) return i; //since div(n1/2 , n2/2 ) is costly op we r doing multiplication 
}
return -1;
}
};
