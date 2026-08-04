//Recursion + Memoization
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
int n;
int t[50001];
int solve(vector<int>& stones, int i){
    if(i>=n)return 0;
    if(t[i] != -1)return t[i];
    int result = stones[i] - solve(stones, i+1);
    if(i+1 < n)
        result = max(result, stones[i]+stones[i+1]-solve(stones,i+2));
    if(i+1 < n && i+2 < n)
        result = max(result, stones[i]+stones[i+1]+stones[i+2]-solve(stones, i+3));

    return t[i] = result;
}
    string stoneGameIII(vector<int>& stones) {
n = stones.size();
memset(t, -1, sizeof(t));
int diff = solve(stones, 0);//Alice-Bob
if(diff < 0)return "Bob";
else if(diff > 0)return "Alice";
return "Tie";
    }
};

//Bottom Up
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
int n;
int t[50001];
string stoneGameIII(vector<int>& stones) {
n = stones.size();
memset(t, 0, sizeof(t));

for(int i=n-1; i>=0; i--){
t[i] = stones[i] - t[i+1];
if(i+2 <= n)
    t[i] = max(stones[i]+stones[i+1]-t[i+2], t[i]);
if(i+3 <= n)
    t[i] = max(stones[i] + stones[i+1] + stones[i+2]-t[i+3], t[i]);
}

if(t[0]< 0)return "Bob";
else if(t[0] > 0)return "Alice";
return "Tie";
    }
};
