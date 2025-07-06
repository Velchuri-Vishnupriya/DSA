class FindSumPairs {
public:
   vector<int> nums1, nums2;
   unordered_map<int,int> mp;
    FindSumPairs(vector<int>& Nums1, vector<int>& Nums2) {
     nums1 = Nums1;
        nums2 = Nums2;
            for(auto& it: nums2){
            mp[it]++;
        }
    }
    
    void add(int idx, int val) {
        mp[nums2[idx]]--;
        nums2[idx]+=val;
        mp[nums2[idx]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(int i=0; i<nums1.size(); i++){
int target = tot - nums1[i];
cnt += mp[target];
        }
        return cnt;
    }
};
