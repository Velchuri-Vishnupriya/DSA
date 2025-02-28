//Using Recurrsion
//T.C : O(m*n)
//S.C: O(m*n);
class Solution {
public:
int t[1001][1001];
int solve(string& text1,string& text2,int m,int n){
    if(m==0 || n==0){
        return t[m][n]=0;
    }

    if(t[m][n]!= -1) return t[m][n];

    if(text1[m-1]==text2[n-1]){
        return t[m][n]=1+solve(text1,text2,m-1,n-1);
    }

    return t[m][n]=max(solve(text1,text2,m-1,n),solve(text1,text2,m,n-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
memset(t,-1,sizeof(t));
return solve(text1,text2,m,n);
    }
};

//Using Bottom Up
//T.C: O(n^2)
//T.C: O(m*n)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();

vector<vector<int>> t(m+1,vector<int>(n+1));

for(int i=0;i<m+1;i++){
    for(int j=0;j<n+1;j++){
        if(i==0 || j==0){t[i][j]=0;}

        else if(text1[i-1]==text2[j-1]) t[i][j]=1+t[i-1][j-1];

        else
        t[i][j]=max(t[i][j-1],t[i-1][j]);
    }
}
    return t[m][n];}
};

//Bottom up (space optimized)
//Since we are using results of only two rows t[i] and t[i-1] we can take only two rows
//T.C: O(m*n)
//S.C: O(n)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();

vector<vector<int>> t(2,vector<int>(n+1));

for(int i=0;i<m+1;i++){
    for(int j=0;j<n+1;j++){
        if(i==0 || j==0){t[i%2][j]=0;}

        else if(text1[i-1]==text2[j-1]) t[i%2][j]=1+t[(i+1)%2][j-1];

        else
        t[i%2][j]=max(t[i%2][j-1],t[(i+1)%2][j]);
    }
}
    return t[m%2][n];}
};
