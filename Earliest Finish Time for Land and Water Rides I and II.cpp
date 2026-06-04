//T.C : O(n+m)
//S.C : O(1)
class Solution {
public:

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int landFinish = INT_MAX;

        for(int i=0; i<n; i++){
            landFinish = min(landFinish, landStartTime[i] + landDuration[i]);
        }

        int waterFinish = INT_MAX;

        for(int j=0; j<m; j++){
            waterFinish = min(waterFinish, waterStartTime[j] + waterDuration[j]);
            ans = min(ans, max(landFinish, waterStartTime[j]) + waterDuration[j]);
        }

        for(int i=0; i<n; i++){
            ans = min(ans, max(waterFinish, landStartTime[i])+landDuration[i]);
        }
return ans;}
};
