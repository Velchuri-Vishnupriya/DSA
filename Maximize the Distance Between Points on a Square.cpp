//T.C : O(log side * nCk * k)
//S.C : O(k)
class Solution {
public:
int manhattanDist(vector<int>& p1, vector<int>& p2){
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}
bool check(vector<vector<int>>& points, int k, int mid, int i, vector<int>& chosen){
    if(chosen.size() == k)return true;

    for(int p = i; p < points.size(); p++){
        bool valid = true;

        for(int idx : chosen){
            if(manhattanDist(points[p], points[idx]) < mid){
                valid = false;
                break;
            }
        }

        if(!valid){continue;}

        chosen.push_back(p);
        if(check(points, k, mid, p+1, chosen))return true;

        chosen.pop_back();
    }
    return false;
}
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int l = 0;
        int r = 2*side;

        int result = 0;

        while(l <= r){
            int mid = l + (r-l)/2;

            vector<int> chosen;

            if(check(points, k, mid, 0, chosen)){
                result = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
    return result;
    }
};
