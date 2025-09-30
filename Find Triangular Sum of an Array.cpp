//Approach - 1 - USing O(n) space
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> num1 = nums;
        int n = num1.size();
        vector<int> newnums;
        while(n > 1){
            for(int i=0; i < num1.size() - 1; i++){
                newnums.push_back((num1[i]+num1[i+1])%10);
            }
            num1 = newnums;
            newnums.clear();
            n--;
        }
    return num1[0];
    }
};

//Approach - 2 using constant space
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int triangularSum(vector<int>& nums) {
   int n = nums.size();
   for(int i = n ; i > 1; i--){
    for(int j = 0; j < i-1; j++){
        nums[j] = (nums[j] + nums[j+1])%10;
    }
   }
    return nums[0];
    }
};
