// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    int numOfWays(int n) {
       const int MOD = 1e9 + 7;

       long long dpA = 6; //ABC variants
       long long dpB = 6; //ABA variants

       for(int row = 2; row <= n; row++){
        long long new_dpA = ((dpA % MOD)*2 + (dpB % MOD)*2) % MOD; //BAB CAB BCA BCB
        long long  new_dpB = ((dpA % MOD)*2 + (dpB % MOD)*3) % MOD; //BAB CAB BCB BAC CAC

        dpA = new_dpA;
        dpB = new_dpB;
       }
       return (int)(dpA + dpB) % MOD;
    }
};

// T.C : O(n*12*12*3)
// S.C : O(n)

class Solution {
public:
int M = 1e9 + 7;
vector<vector<int>>t;
//12 possible first rows
vector<string> states = {"RYG","RYR","RGY","RGR","YRG","YGR","YGY","YRY","GRY","GRG","GYG","GYR"};

 int solve(int n, int prev){
    if(n == 0)return 1;

    if(t[n][prev] != -1) return t[n][prev];

    string prevRow = states[prev];
    
    int result = 0;

    for(int curr = 0; curr < 12; curr++){
        if(states[curr] == prevRow) continue;

        bool color = true;
        string currRow = states[curr];

        for(int i = 0; i < 3; i++){
            if(currRow[i] == prevRow[i]){
                color = false;
                break;
            }
        }

        if(color == true){
            result = (result + solve(n-1,curr)) % M;
        }
    }
 return t[n][prev] = result;
 }
    int numOfWays(int n) {
        int result = 0;
        t.resize(n, vector<int>(12, -1));

        for(int i = 0; i < 12; i++){//choosing first row
        //n-1 remaining
        result = (result + solve(n-1,i)) % M;
        }

        return result;
    }
};
