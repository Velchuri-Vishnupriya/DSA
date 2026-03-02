//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(); // rows = cols

        vector<int> endZeros(n, 0);
        //count of consecutive zeroes from the right end

        for(int i = 0; i < n; i++){//O(n)
            int j = n - 1; //start from end

            int count = 0;
            while(j >= 0 && grid[i][j] == 0){//O(n)
                count++;
                j--;
            }
            endZeros[i] = count;
        }

        int steps = 0;

        for(int i = 0; i < n; i++){//O(n)
            int need = n - i - 1;

            int j = i;

            while(j < n && endZeros[j] < need){//O(n)
                j++;
            }

            if(j == n)return -1;

            steps += (j-i);

             while(j > i){//O(n)
                swap(endZeros[j], endZeros[j-1]);
                j--;
             }
        }
  return steps;
  }
};
