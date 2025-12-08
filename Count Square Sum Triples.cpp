//Approach-1
//T.C : O(n^2)
class Solution {
public:
int n;
    int countTriples(int N) {
        n = N;
        int count = 0;
        for(int a = 1; a < n; a++){
            for(int b = 1; b < n; b++){
                int root = sqrt(a*a + b*b);
                int c = a*a + b*b;
                if(root*root == c && root <= n){
                    count++;
                }
            }
        }
   return count; }
};
