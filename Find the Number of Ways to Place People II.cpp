//This is same as it's part 1 - part 1 is leetcode 3205
//Optimized Approach
//T.C : O(n^2)
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
       int n = points.size();
       int result = 0;
       auto lambda = [](vector<int> pt1, vector<int> pt2){
        if(pt1[0] == pt2[0]) return pt1[1] > pt2[1];
        return pt1[0] < pt2[0];
       };

       sort(points.begin(), points.end(), lambda);

       for(int i = 0; i < n; i++){
        int x1 = points[i][0];
        int y1 = points[i][1];

        int maxY = INT_MIN;

        for(int j = i+1; j < n; j++){
            int x2 = points[j][0];
            int y2 = points[j][1];

            if(y2 > y1) continue; //ye wala point A se uppar chala gaya
            if(y2 > maxY){
                result++;
                maxY = y2;
            }
        }
       }
       return result;
    }
};
