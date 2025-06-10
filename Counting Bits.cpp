//Approach - 1
//T.C: O(n*32)
//S.C: O(1)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0] = 0 ;
        for(int i=1; i<=n; i++){//O(n)
            int countOnes = 0;
            for(int k=0; k<=31; k++){//O(32)
                int temp = (1 << k);
                if((i & temp) != 0) countOnes ++;
            }
            ans[i] = countOnes++;
        }
    return ans;}
};

//Approach - 2
//T.C: O(n)
//S.C: O(1)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0] = 0 ;
        for(int i=1; i<=n; i++){//O(n)
          if(i%2 == 0) {ans[i] = ans[i/2];}
          else {ans[i]= ans[i/2] + 1;}
        }
    return ans;}
};
