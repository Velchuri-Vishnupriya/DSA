//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    int total = 0;

    sort(begin(intervals), end(intervals), [](auto& v1, auto& v2){
        if(v1[0] == v2[0])return v1[1] > v2[1];
        return v1[0] < v2[0];
    });
    
    int maxEnd = INT_MIN;
    for(auto& it : intervals){
    if(it[1] > maxEnd){
        total++;
        maxEnd = it[1];
    }
    }
    return total;
    }
};
