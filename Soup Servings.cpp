//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    typedef pair<int,int> P;
    vector<P> serves{{4,0},{3,1},{2,2},{1,3}}; // each unit = 25 ml
    vector<vector<double>> t;

    double solve(int A, int B) {
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;

        if (t[A][B] != -1.0) return t[A][B];

        double prob = 0.0;
        for (auto& p : serves) {
            prob += solve(A - p.first, B - p.second);
        }
        return t[A][B] = 0.25 * prob;
    }

    double soupServings(int n) {
        if (n > 5000) return 1.0; // optimization for large n
        int N = (n + 24) / 25; // convert ml to 25 ml units
        t.assign(N + 1, vector<double>(N + 1, -1.0));
        return solve(N, N);
    }
};
