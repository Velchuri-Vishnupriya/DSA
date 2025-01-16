//Approach-1
//T.S: O(m+n);
//S.C: O(m+n);
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        unordered_map<int, int> mp;

        // Build frequency map for nums1
        for (auto &it : nums1) {
            mp[it] =(mp[it]+n)%2; // Contribution based on nums2 size
        }
        // Update frequency map for nums2
        for (auto &it : nums2) {
            mp[it] = (mp[it]+m)%2; // Contribution based on nums1 size
        }

        int result = 0;
        // Calculate XOR for numbers with odd frequency
        for (auto it : mp) {
            int num = it.first;
            int freq = it.second;
            if (freq % 2 != 0) { // Odd frequency
                result ^= num;
            }
        }
        return result;
    }
};

//Approach-2
//T.s: O(m+n)
//S.C: O(1)
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
      int XOR=0;
      if(n%2 != 0){
        for(int& it:nums1){
            XOR^=it;
        }
      }
      if(m%2 !=0){
        for(int& it:nums2){
            XOR^=it;
        }
      }
      return XOR;
    }
};

