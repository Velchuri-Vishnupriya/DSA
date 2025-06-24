//Approach -1 Brute force
//T.C:O(n^2)
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> vec;
        set<int> st;
        int n = nums.size(); 
        for(int j=0; j<n; j++){
if(nums[j] == key){
    for(int i=0; i<n; i++){
        if(abs(i-j) <= k) st.insert(i);
    }
}
        }
        for(int val:st){
            vec.push_back(val);
        }
        return vec;  }
};

//Approach - 2
//T.C : O(2*n)
//T.C:O(2*n)
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> vec;
    
        int n = nums.size(); 
        for(int j=0; j<n; j++){
if(nums[j] == key){
    int left = max(0,j-k);
    int right = min(n-1,j+k);
    if(!vec.empty() && vec.back() >= left) left = vec.back()+1;
    for(int i=left; i<=right; i++){
    vec.push_back(i);
    }
    }
}
        

        return vec;  }
};
