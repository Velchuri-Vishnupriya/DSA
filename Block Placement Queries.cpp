//Brute Force
//O(Q * len(set))
//O(sizof(set))
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
vector<bool> result;

set<int> st;

for(auto& query: queries){
    if(query[0] == 1){
        st.insert(query[1]);
    }else{
        int x = query[1];
        int sz = query[2];

        int prev = 0;
        bool found = false;

        for(int p : st){
            if(p > x){
                break;
            }
            if(p - prev >= sz){
                found = true;
                break;
            }
            prev = p;
        }
        if(x - prev >= sz)found = true;
        result.push_back(found);
    }
}
    return result;
    }
};
