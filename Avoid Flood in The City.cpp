//T.C : O(n*logn) - Binary search is used
//S.C : O(n)
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rain) {
        int n = rain.size();

        unordered_map<int,int> mp;
        set<int> st; 

        vector<int> ans(n, 1);

        for(int i = 0; i < n; i++){
        int lake = rain[i];

        if(lake == 0){
            st.insert(i);
        }else{
            ans[i] = -1;
            if(mp.count(lake)){
                auto it = st.lower_bound(mp[lake]);

                if(it == st.end()){//lake can not be dried
                return {};
                }
                int day = *it;
                ans[day] = lake;
                st.erase(it);
            }
                mp[lake] = i;
            
        }
        }
   return ans; }
};
