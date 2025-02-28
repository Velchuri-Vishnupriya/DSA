//Using Bottom Up Approach
//T.S : O(n^2)
//S.C: O(m*n)

class Solution {
    public:
    int shortestCommonSupersequence(string s1, string s2) {
         int m,n;
         m=s1.length();
        n=s2.length();
        vector<vector<int>> t(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){t[i][j]=0;}
                else if(s1[i-1]==s2[j-1]){
                   t[i][j]=1+t[i-1][j-1]; 
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        int LCS=t[m][n];
        int extra_eles1=m-LCS;
        int extra_eles2=n-LCS;
        return LCS+extra_eles1+extra_eles2;
      
    }
};
