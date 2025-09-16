//T.C : O(2*n) each of the element is visited at max twice once while pushing nd the other time while doing pop
//S.C : O(1)
class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int>& nums) {
vector<int> result;
for(auto& num : nums){
    while(!result.empty()){
        int prev = result.back();
        int curr = num;

        int GCD = gcd(prev,curr);
        if(GCD == 1) break; 
            int LCM = prev/gcd(prev,curr)*curr;
            result.pop_back();
            num = LCM;
    
}
result.push_back(num);
    }
  return result;}
};
