//Approach - 1
//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edge)
    {
        int count = 0 ;
        long long sum = 0;
        long long loss = LLONG_MAX;
        for(auto& it: nums){
            int num = it ^ k;
            if(num > it) {count++; sum+=num;}
            else sum += it;
            loss =min(loss , (long long)abs(num-it));
        }
    if(count %2 !=0) {
   return sum - loss ; }
else return sum;
    }
};

//Approach - 2
//T.C: O(nlogn);
//S.C: O(n);
class Solution {
public:
    typedef long long ll;
    ll maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edge)
    {
      vector<int> fayda;
      ll normalsum =0;
      for(int i=0; i<nums.size(); i++){
        fayda.push_back((nums[i]^k) - nums[i]);
        normalsum += (ll)  nums[i];
      }
      sort(fayda.begin(),fayda.end(),greater<int>());
      for(int i=0;i<fayda.size()-1; i+=2){
        if(fayda[i] + fayda[i+1] > 0) normalsum += (ll)(fayda[i]+fayda[i+1]);

      }  
      return normalsum;  }
};
