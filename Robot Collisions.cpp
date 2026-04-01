//T.C : O(nlogn)
//S.C : O(n) - Unordered_map + stack
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        unordered_map<int,int> mp;

        int n = positions.size();

        for(int i=0; i < n;i ++){
            mp[positions[i]] = i;
        }

        sort(begin(positions), end(positions));

        stack<pair<char,int>> st;
        
        for(int i = 0; i < n; i++){//each ele is pushed in and popped out at most only once  O(n) + O(n)
            int idx = mp[positions[i]];

            while(!st.empty() && st.top().first == 'R' && directions[idx] == 'L' && healths[idx] != INT_MIN){
                int idx2 = st.top().second;
                int val1 = healths[idx];
                int val2 = healths[idx2];

                if(val1 == val2){
                    st.pop();
                    healths[idx] = INT_MIN;
                    healths[idx2] = INT_MIN;
                    break;
                }else if(val1 > val2){
                    healths[idx]--;
                    st.pop();
                    healths[idx2] = INT_MIN;
                }else{//stack top more val
                    healths[idx2]--;
                    healths[idx] = INT_MIN;
                    break;
                }
            } 

             if(healths[idx] != INT_MIN)
             { st.push({directions[idx], idx});
             }

        }

        vector<int> ans;

        for(int i=0; i<n; i++){
            if(healths[i] != INT_MIN){
                ans.push_back(healths[i]);
            }
        }
   return ans;
    }
};
