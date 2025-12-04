//T.C : O(n*n)
//S.C : O(n)
class Solution {
public:
     int countTrapezoids(vector<vector<int>>& points) {
    int n = points.size();

    //slope -> {intercepts}
    unordered_map<float,vector<float>> slopeIntercept;

    unordered_map<int, vector<float>> midPointMap;

    int result = 0;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = points[j][0];
            int y2 = points[j][1];

            int dx = x2-x1;
            int dy = y2-y1;

            float slope,intercept;
            if(x2 == x1){
                //dx = 0;
                slope = 1e9 + 7;
                intercept = x1;
            }else{
                slope = (float)(dy)/dx;
                intercept = (float)(y1*dx - x1*dy)/dx;
            }

            int midPointKey = (x1 + x2)*10000 + (y1+y2);

            slopeIntercept[slope].push_back(intercept);
            midPointMap[midPointKey].push_back(slope);
        }
    }

    for(auto& it : slopeIntercept){
        map<float, int> mp; //intercept->count
        for(auto& i : it.second){
            mp[i]++;
        }

        int prevHorizLines = 0;
        for(auto& val : mp){
            int count = val.second;
            result += count * prevHorizLines; //counts duplicates aslo

            prevHorizLines += count;
        }
    }

for(auto& it : midPointMap){
        map<float, int> mp; //intercept->count
        for(auto& i : it.second){
            mp[i]++;
        }

        int prevHorizLines = 0;
        for(auto& val : mp){
            int count = val.second;
            result -= count * prevHorizLines; //removing duplicates

            prevHorizLines += count;
        }
    }


    return result;
    }
};
