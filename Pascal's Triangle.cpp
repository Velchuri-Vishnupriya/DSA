//T.C : O(n^2)
class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n == 1) return {{1}};
        if(n == 2) return {{1}, {1,1}};
        vector<vector<int>> res;
        res.push_back({1});
        res.push_back({1,1});
        for(int i=2; i<n; i++){//O(n)
vector<int> temp = res[i-1];
vector<int> toAdd;
toAdd.push_back(1);
for(int j=1; j<temp.size(); j++){//O(n-1)
toAdd.push_back(temp[j]+temp[j-1]);
}
toAdd.push_back(1);
        res.push_back(toAdd);}
    return res;}
};
