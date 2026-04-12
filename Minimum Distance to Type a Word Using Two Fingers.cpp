//Approach 1 - using 5D dp array
//T.C : O(n*7^4)
//S.C : O(n*7^4) 
class Solution {
public:
int dp[301][7][7][7][7];

pair<int,int> getCoord(char ch){
    int val = ch - 'A';
    return {val/6, val%6};
}

int getDistance(int x1, int y1, int x, int y){
    return abs(x1-x) + abs(y1-y);
}

int solve(string& word, int i, int x1, int y1, int x2, int y2){
    if(i >= word.length()){
        return 0;
    }
    if(dp[i][x1+1][y1+1][x2+1][y2+1] != -1)return dp[i][x1+1][y1+1][x2+1][y2+1];

    auto [x,y] = getCoord(word[i]);
    //none of the fingers used
    if(x1 == -1 && y1 == -1 && y2 == -1 && x2 == -1){
        return dp[i][x1+1][y1+1][x2+1][y2+1] = solve(word, i+1, x,y, x2, y2);
    }

    //finger 2 is not used
    if(x2 == -1 && y2 == -1){
        int moveF2 = solve(word, i+1, x1, y1, x, y);
        int moveF1 = getDistance(x1, y1, x, y) + solve(word, i+1, x, y, x2, y2);
        return dp[i][x1+1][y1+1][x2+1][y2+1] = min(moveF1, moveF2);
    }

    //if both f1 and f2 were used
    int moveF1 = getDistance(x1, y1, x, y) + solve(word, i+1, x, y, x2, y2);
    int moveF2 = getDistance(x2, y2, x, y) + solve(word, i+1, x1, y1, x, y);
     
    return dp[i][x1+1][y1+1][x2+1][y2+1] = min(moveF1, moveF2);
}
    int minimumDistance(string s) {
       //finger 1 = {x1, y1}
       //finger 2 = {x2, y2}
       memset(dp, -1, sizeof(dp));
       return solve(s, 0, -1, -1, -1, -1);
       }
};

//Approach 2 - using 3D dp array
//T.C : O(n*27*27)
//S.C : O(n*27*27) 
class Solution {
public:
int dp[301][27][27];

pair<int,int> getCoord(char ch){
    int val = ch - 'A';
    return {val/6, val%6};
}

int getDistance(int pos1, int pos2){
    auto[x1, y1] = getCoord(pos1);
    auto[x2, y2] = getCoord(pos2);
    return abs(x1-x2) + abs(y1-y2);
}

int solve(string& word, int i, int f1, int f2){
    if(i >= word.length()){
        return 0;
    }
    if(dp[i][f1][f2] != -1)return dp[i][f1][f2];

    int curr = word[i] - 'A';

    //none of the fingers used
    if(f1 == 26 && f2 == 26){
        return dp[i][f1][f2]= solve(word, i+1, curr, f2);
    }

    //finger 2 is not used
    if(f2 == 26){
        int moveF2 = solve(word, i+1, f1, curr);
        int moveF1 = getDistance(f1, curr) + solve(word, i+1, curr, f2);
        return dp[i][f1][f2] = min(moveF1, moveF2);
    }

    //if both f1 and f2 were used
    int moveF1 = getDistance(f1, curr) + solve(word, i+1,curr, f2);
    int moveF2 = getDistance(f2, curr) + solve(word, i+1, f1, curr);
     
    return dp[i][f1][f2] = min(moveF1, moveF2);
}
    int minimumDistance(string s) {
       //finger 1 = char val
       //finger 2 = char val
       memset(dp, -1, sizeof(dp));
       return solve(s, 0, 26, 26);
       }
};
