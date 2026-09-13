//T.C : O(n^4)
//S.C : O(1)
class Solution {
public:
int n;
int countOverlap(vector<vector<int>>& A, vector<vector<int>>& B, int rowOff, int colOff){
    int count = 0;
    for(int i=0; i<n; i++){//O(n)
        for(int j=0; j<n; j++){//O(n)
            int i_B = i + rowOff;
            int j_B = j + colOff;
            if(i_B >=0 && i_B < n && j_B >= 0 && j_B < n){
                if(A[i][j] == 1 &&  B[i_B][j_B] == 1)count++;
            }
        }
    }
return count;
}
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
       n = A.size();
       //n*n matrix rows=cols=n

       int maxOverlap = 0;

       //O(n^4)
       for(int rowOff = -n+1; rowOff < n; rowOff++){//O(n+n-1)~O(2*n)~O(n)
        for(int colOff = -n+1; colOff < n; colOff++){//O(n)
            maxOverlap = max(maxOverlap, countOverlap(A,B,rowOff,colOff));//O(n^2)
        }
       }
       return maxOverlap;
    }
};
