//Brute Force
//T.C : O(n^3)
class Solution {
public:
//lower bound and upper bound
    int numberOfPairs(vector<vector<int>>& points) {
       int n = points.size();
       int result = 0;

       for(int i=0; i < n; i++){
        //A upper wala point
        int x1 = points[i][0];
        int y1 = points[i][1];

        //Find B - lowe point
        for(int j=0; j<n; j++){
            if(i == j) continue;

            int x2 = points[j][0];
            int y2 = points[j][1];

            if(x1 <= x2 && y1>=y2){
                bool hasPoint = true;
                for(int k=0; k<n; k++){
                    if(k==i || k==j) continue;
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    if(x3 >= x1 && x3 <= x2 && y3 <= y1 && y3 >= y2){
hasPoint = false;
                 break;   }
                }
                if(hasPoint) result++;
            }
        }
       }
       return result;
    }
};

//Optimized Approach
//T.C : O(n^2)
class Solution {
public:
//lower bound and upper bound
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
