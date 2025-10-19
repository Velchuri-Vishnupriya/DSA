//Try 1
//T.C : O(n*k)
//S.C : O(n)
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        set<int> st;
         for(int i = 0; i < nums.size(); i++){
            bool isPossible = false;
for(int j = -k; j <= k; j++){
    int val = nums[i] + j;
    if(!st.count(val)){
        st.insert(val);
        isPossible = true;
        break;
    }
}
if(!isPossible) return st.size();
       }
   return st.size(); }
};

//Try 2
//T.C: O()
//S.C: O()
/*class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        set<int> st;
        st.insert(nums[0] + (-k));
        int prev = nums[0] - k;
        for(int i = 1; i < nums.size(); i++){
int curr = prev + 1;
if(curr >= nums[i]-k && curr<= nums[i]+k){
    prev = curr;
    st.insert(curr);
}
        }
   return st.size(); }
};*/

//Solution
//T.C : O(n*log n) + O(n)
//S.C : O(1)
/*class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int prev = INT_MIN;
        int count = 0;
        for(int i = 0; i < n; i++){
            int minVal = nums[i] - k;

            if(prev < minVal){
                 //nums[i] = nums[i] - k;
                 prev = minVal;
                 count++;
            }
            else if(prev < nums[i] + k){
                prev = prev + 1;
                count++;
            }
        }
      return count;  }
};*/
