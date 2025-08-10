//Top - Down with Memoization
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
int n;
vector<vector<int>> t;
    int child1Collect(vector<vector<int>>& fruits){
        int res = 0;
        for(int i =0; i < n; i++){
            res += fruits[i][i];
        }
        return res;
    }

    int child2Collect(int i, int j, vector<vector<int>>& fruits){
        if(i >= n || j < 0 || j >= n ) return 0;

        if(i == n-1 && j == n-1) return 0; //bcs [n-1][n-1] is already taken by C1

        if(i == j || i > j) return 0;

        if(t[i][j] != -1) return t[i][j];

        int bottomLeft  = fruits[i][j] + child2Collect(i+1, j-1, fruits);
        int bottomDown  = fruits[i][j] + child2Collect(i+1, j, fruits);
        int bottomRight = fruits[i][j] + child2Collect(i+1, j+1, fruits);

        return t[i][j] = max({bottomRight, bottomLeft, bottomDown}); 
    }

    int child3Collect(int i, int j, vector<vector<int>>& fruits){
        if(i >= n || i < 0 || j >= n ) return 0;

        if(i == n-1 && j == n-1) return 0; //bcs [n-1][n-1] is already taken by C1

        if(i == j || i < j) return 0;

        if(t[i][j] != -1) return t[i][j];

        int bottomRight  = fruits[i][j] + child3Collect(i+1, j+1, fruits);
        int upRight  = fruits[i][j] + child3Collect(i-1, j+1, fruits);
        int rightCell = fruits[i][j] + child3Collect(i, j+1, fruits);

        return t[i][j] = max({bottomRight, upRight, rightCell}); 
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
       n = fruits.size();
       t.resize(n, vector<int>(n,-1));
       int c1 = child1Collect(fruits);

       int c2 = child2Collect(0, n - 1, fruits);

        int c3 = child3Collect(n-1, 0, fruits);

return c1 + c2 + c3;
    }
};

//Bottom - Up Approach
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
    int n;
    vector<vector<int>> t;

    int child1Collect(vector<vector<int>>& fruits) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += fruits[i][i];
        }
        return res;
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        t.resize(n, vector<int>(n, 0));

        // Nullify cells for child2 & child3
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i + j < n - 1 && i < j) {
                    t[i][j] = 0;
                } else if (i + j < n - 1 && i > j) {
                    t[i][j] = 0;
                } else {
                    t[i][j] = fruits[i][j];
                }
            }
        }

        // Child2 collects fruits (upper diagonal: i < j)
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                t[i][j] += max({
                    t[i - 1][j],
                    t[i - 1][j - 1],
                    (j + 1 < n) ? t[i - 1][j + 1] : 0
                });
            }
        }

        // Child3 collects fruits (below diagonal: i > j)
        for (int j = 1; j < n; j++) {
            for (int i = j + 1; i < n; i++) {
                t[i][j] += max({
                    t[i - 1][j - 1],
                    t[i][j - 1],
                    (i + 1 < n) ? t[i + 1][j - 1] : 0
                });
            }
        }

        int c1 = child1Collect(fruits);
        int c2 = t[n - 2][n - 1];
        int c3 = t[n - 1][n - 2];

        return c1 + c2 + c3;
    }
};
