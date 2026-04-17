//T.C : O(n)
//S.C : O(n)
int reverseNum(int num){
    string s = to_string(num);
    reverse(s.begin(), s.end());
    int reverseNum = stoi(s);
    return reverseNum;
}

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
       unordered_map<int,int> mp;
       int n = nums.size();
    
       int result = INT_MAX;

       for(int i=0; i<n; i++){
        if(mp.find(nums[i]) != mp.end()){
            result = min(result, abs(i-mp[nums[i]]));
        }

        int reverseVal = reverseNum(nums[i]);
        mp[reverseVal] = i;
       }

       return result == INT_MAX ? -1 : result;
       }
};
