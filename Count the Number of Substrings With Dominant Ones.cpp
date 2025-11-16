class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> cumCountOne(n,0);
        cumCountOne[0] = (s[0]=='1' ? 1 : 0);

        for(int i=1; i<n; i++){
            cumCountOne[i] = cumCountOne[i-1] + (s[i] == '1' ? 1 : 0);
        }

        //i nunchi j varaku = cumCount[j] - cumCount[i-1];

        //O(n*n) - worst
        //O(n * )
        //j - i + 1 = L
        //L^2 ~ n
        //L = sqrt(n)
        //O(n * sqrt(n))

        long long result = 0;   // <- your variable was "res" but you used "result"

        for(int i = 0; i< n; i++){
            for(int j = i; j < n; j++){
                
                int oneCount = cumCountOne[j] - (i - 1 >= 0 ? cumCountOne[i-1] : 0);
                int zeroCount = (j - i + 1) - oneCount;

                if(1LL * zeroCount * zeroCount > oneCount){
                    int wasteIndices = (zeroCount * zeroCount) - oneCount;

                    // to avoid j going out of bounds
                    int jump = wasteIndices - 1;
                    j = min(j + jump, n - 1);

                } else if(1LL * zeroCount * zeroCount == oneCount){
                    result += 1;

                } else {
                    result += 1;

                    //try ro see how much you can shift j such that substring is still valid
                    int sq = sqrt(oneCount);
                    int k = sq - zeroCount;

                    if(k < 0) k = 0;  // avoid negative jumps

                    int nxt = j + k;

                    if(nxt >= n){
                        //idx out of bound
                        result += (n - j - 1);
                        j = n - 1;
                    } else {
                        result += k;
                        j = nxt;
                    }
                }
            }
        }

        return result;
    }
};
