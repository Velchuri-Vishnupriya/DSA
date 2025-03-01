//T.S: O(m*n)
//S.C: O(m*n)

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();

vector<vector<int>> t(m+1,vector<int>(n+1));

for(int i=0;i<m+1;i++){
    for(int j=0;j<n+1;j++){
        if(i == 0 || j == 0)
                    t[i][j] = 0;
else if(s1[i-1]==s2[j-1]) t[i][j]=1+t[i-1][j-1];
else t[i][j]=max(t[i-1][j],t[i][j-1]);

    }
}

string res="";
int i=m; int j=n;
while(i>0 && j>0){
    if(s1[i-1]==s2[j-1]) {res.push_back(s1[i-1]); i--;j--;
}
else{
    if(t[i-1][j]>t[i][j-1]) i--;
    else j--;}
    }
reverse(res.begin(),res.end());
cout<<res<<"\n";
return t[m][n];
    }
};
