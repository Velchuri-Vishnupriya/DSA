//T.C : O(n*log n)
//S.C : O(n)
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        vector<int> temp = happiness;
        sort(begin(temp), end(temp), greater<int>());
        long long sum = 0;
        int i = 0;
        long long sub = 1;
        int n = temp.size();
        while(k){//O(K)
            sum += (temp[i] > 0 ? (long long)temp[i] : 0);
            i++;
            if(i >= n)break;
            temp[i]-= sub;
            sub++;
            k--;
        }
        return sum;
    }
};
