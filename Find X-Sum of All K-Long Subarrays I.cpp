//T.C : O(n*(k+ k*log k + x)) ~ O(n*k*log k)
//S.C : O(k) (k for map, k for set 2*k ~ k)
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        unordered_map<int,int> mp;
        set<pair<int,int>, greater<>> st;
        
        int i = 0 ;
        int j = k - 1;
        while(j < nums.size()){//O(n)

        for(int k = i; k <= j; k++){//O(k)
            mp[nums[k]]++;
        }

        for(auto& it : mp){//O(k)
            st.insert({it.second,it.first}); //O(log k)
        }

        auto it = st.begin();
        int n = st.size();
        n = min(n,x);
        int ans = 0;
        for(int i = 0;i < n; i++){//O(x)
int freq = it->first;
int num = it->second;
ans += (freq*num);
++it;
        }
        res.push_back(ans);
         i++;
         j++;
         st.clear();
         mp.clear();
        }
        
   return res; }
};
