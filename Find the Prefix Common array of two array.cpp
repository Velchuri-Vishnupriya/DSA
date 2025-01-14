//T.S: O(n^3)
//S.c :O(1)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> result; // Result array to store the prefix common counts
        for (int i = 0; i < A.size(); i++) {
            int count = 0;
            for (int x = 0; x <= i; x++) { // Iterate over A[0:i]
                for (int y = 0; y <= i; y++) { // Iterate over B[0:i]
                    if (B[y] == A[x]) {
                        count++;
                        break; // Stop further checks for A[x] in B
                    }
                }
            }
            result.push_back(count); // Add count to the result array
        }
        return result;
    }
};

//Approach-2:
//T.S: O(n^2)
//S.C: O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> result;
        vector<bool> PA(n+1,false);
        vector<bool>PB(n+1,false);
        for(int i=0;i<n;i++){
            PA[A[i]]=true;
            PB[B[i]]=true;
            int count=0;
            for(int j=1;j<=n;j++){
                if(PA[j]==true && PB[j]==true){count++;}
            }
            result.push_back(count);
        }
        return result;
    }
};

//T.S : O(n)
//S.C :O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> result;
       unordered_map<int,int> mp;
       int cnt=0;
       for(int i=0;i<n;i++){
        mp[A[i]]++;
        if(mp[A[i]]==2){cnt++;}
mp[B[i]]++;
if(mp[B[i]]==2){cnt++;}
result.push_back(cnt) ;      }
  return result;  }
};
