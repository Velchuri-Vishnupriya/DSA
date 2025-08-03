//T.C : O(k * log n)
//S.C : O(n)
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> prefixSum(n); //fruits prefixSum
        vector<int> positions(n); //already sorted

        for(int i = 0; i < n; i++){
            positions[i] = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i-1] : 0);
        }

        int maxFruits  = 0;
        for(int d = 0; d <= k/2; d++){//O(k/2)
            //case 1 left -> right
            int remain = k -2*d;
            int i = startPos - d;
            int j = startPos + remain;

            int left = lower_bound(begin(positions), end(positions),i) - begin(positions);//O(log n)
            int right = upper_bound(begin(positions), end(positions),j) - begin(positions) - 1;
if(left <= right){
            int sum = (right < n ? prefixSum[right] : 0 ) - (left > 0 ? prefixSum[left - 1] : 0); 
            maxFruits = max(sum , maxFruits);}

              //case 2 right -> left
            remain = k -2*d;
            j = startPos + d;
            i = startPos - remain;

            left  = lower_bound(begin(positions), end(positions),i) - begin(positions);
            right = upper_bound(begin(positions), end(positions),j) - begin(positions) - 1;
if(left <= right){
            int sum =(right < n ? prefixSum[right] : 0) - (left > 0 ? prefixSum[left - 1] : 0); 
            maxFruits = max(sum , maxFruits);
}
        }

  return maxFruits;  }
};
