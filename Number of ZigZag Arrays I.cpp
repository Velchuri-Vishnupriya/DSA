//Top-Down - TLE
//T.C : O(N*M*M)
//S.C : O(N*M)
class Solution {
public:
typedef long long ll;
int MOD = 1e9 + 7;
int N, M;

int t[2001][2001][2];//N*M*2*M O(N*M^2)
int solve(int i, int preVal, bool increasing){

    if(i == N)return 1; //found a valid zif zag array

    ll result = 0;

    if(t[i][preVal][increasing] != -1)return t[i][preVal][increasing];

    if(increasing){
        for(int nextVal = preVal + 1; nextVal <= M; nextVal++){//O(M)
            result = (result + solve(i+1, nextVal, false)) % MOD;
        }
    }else{
        for(int nextVal = 1; nextVal < preVal; nextVal++){
            result = (result + solve(i+1, nextVal, true)) % MOD;
        }
    }

    return t[i][preVal][increasing] = result;
}
    int zigZagArrays(int n, int l, int r) {
       N = n;
       M = r - l + 1;
       
       ll result = 0;

       memset(t, -1, sizeof(t));

       for(int startVal = 1; startVal <= M; startVal++){
        //i=0 we have put startVal;

        //increasing
        result = (result + solve(1, startVal, true)) % MOD;

        //decreasing
        result = (result + solve(1, startVal, false)) % MOD;

       }
    return result;
    }
};

//Bootom Up - TLE
//T.C : O(N*M*M)
//S.C : O(N*M)
class Solution {
public:
int MOD = 1e9 + 7;
typedef long long ll;

int zigZagArrays(int n, int l, int r){
int N = n;
int M = r-l+1;

ll t[2001][2001][2]; //DP array
memset(t,0, sizeof(t));

//Base case
for(int prevVal = 1; prevVal <= M; prevVal++){
    t[N][prevVal][0] = 1;
    t[N][prevVal][1] = 1;
}

for(int i=N-1; i >= 0; i--){
    for(int prevVal=1; prevVal <= M; prevVal++){

        for(int nextVal = prevVal + 1; nextVal <= M; nextVal++){
            t[i][prevVal][1] = (t[i][prevVal][1] + t[i+1][nextVal][0]) % MOD;
        }

        for(int nextVal = 1; nextVal < prevVal; nextVal++){
            t[i][prevVal][0] = (t[i][prevVal][0] + t[i+1][nextVal][1]) % MOD;
        }
    }
}

ll result = 0;
for(int startVal = 1; startVal <= M; startVal++){
    result = (result + t[1][startVal][1]) % MOD;
    result = (result + t[1][startVal][0]) % MOD;
}
return result;
}
};

//Using cummulative sum
//T.C : O(N*M)
//S.C : O(N*M)
class Solution {
public:
int MOD = 1e9 + 7;
typedef long long ll;

int zigZagArrays(int n, int l, int r){
int N = n;
int M = r-l+1;

ll t[2001][2001][2]; //DP array


//Base case
for(int prevVal = 1; prevVal <= M; prevVal++){
    t[N][prevVal][0] = 1;
    t[N][prevVal][1] = 1;
}

for(int i=N-1; i >= 0; i--){
    vector<ll> cumSum1(M+1, 0);
    vector<ll> cumSum0(M+1, 0);

    for(int val=1; val <= M; val++){
        cumSum0[val] = (cumSum0[val-1] + t[i+1][val][0]) % MOD;
        cumSum1[val] = (cumSum1[val-1] + t[i+1][val][1]) % MOD;
    }
    
        for(int prevVal=1; prevVal <= M; prevVal++){
            t[i][prevVal][1] = (cumSum0[M] - cumSum0[prevVal] + MOD) % MOD;
            t[i][prevVal][0] = cumSum1[prevVal-1] % MOD;
         }
}

ll result = 0;
for(int startVal = 1; startVal <= M; startVal++){
    result = (result + t[1][startVal][1]) % MOD;
    result = (result + t[1][startVal][0]) % MOD;
}
return result;
}
};
