//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sum = 0;
        int n = points.size();

        for(int i = 0; i < n-1; i++){
            auto p1 = points[i];
            auto p2 = points[i+1];
            int x1 = p1[0]; int x2 = p2[0];
            int y1 = p1[1]; int y2 = p2[1];

            int maxVal = max(abs(x2-x1), abs(y2-y1));
            sum += maxVal;
        }
    return sum;
    }
};
