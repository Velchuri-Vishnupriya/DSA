//T.C : O(n + k) ~ O(n)
//S.C : O(k)
class Solution {
public:
    long long countTrapezoids(vector<vector<int>>& points) {

        unordered_map<int, long long> mp;

        int n = points.size();
        for(int i = 0; i < n; i++){//O(n)
            int y = points[i][1];
            mp[y]++;    // count how many points per Y
        }

        vector<long long> seg;

        // computing C(f,2) for each y-group
        for(auto &it : mp){//O(k)
            long long f = it.second;
            if(f >= 2){
                seg.push_back(f * (f - 1) / 2);
            }
        }

        long long sum = 0;
        long long sumSq = 0;

        // computing sum(seg) and sum(seg^2)
        for(long long v : seg){//O(k)
            sum += v;
            sumSq += v * v;
        }

        // formula: (sum^2 - sumSq) / 2
        long long result = (sum * sum - sumSq) / 2;

        return result  % (long long)(1e9 + 7);
    }
};
