//Approach - 1 TLE
//T.C : O(n*n)
//S.C : O(n)
class Solution {
public:
     int minOperations(vector<int>& nums) {
unordered_set<int> st(begin(nums), end(nums)); //O(n) space

int n = nums.size();

int ops = 0;

for(int target : st){
    if(target == 0) continue;

    bool Break = true;

    for(int i = 0; i < n; i++){
        if(nums[i] == target){
            if(Break){
                ops ++;
                Break = false;
            }
        }
        if(nums[i] < target){
            Break = true;
        }
    }
}
    return ops;
    }
};

//Approach - 2 
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
     int minOperations(vector<int>& nums) {
stack<int> st;

int ops = 0;

for(int i = 0; i < nums.size(); i++){
    while(!st.empty() && st.top() > nums[i]){
        st.pop();
    }
    
    if(nums[i] == 0) continue;

    if(st.empty() || st.top() < nums[i]){
        st.push(nums[i]);
        ops++;
    }
}
   return ops; }
};
