//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int total = 0;

        sort(begin(cost), end(cost));

        for(int i=n-1; i>=0; i-=3){
            int sum = cost[i];
            if(i-1 >= 0) sum += cost[i-1];
            total += sum;
        }
        return total;
    }
};
