//T.C : O(n) -> Sliding Window
class Solution {
public:
    int getState(int count_a, int count_b){
        int parity_a = count_a % 2;
        int parity_b = count_b % 2;

        if(parity_a == 0 && parity_b == 0) return 0; // even-even → 00
        if(parity_a == 0 && parity_b == 1) return 1; // even-odd  → 01
        if(parity_a == 1 && parity_b == 0) return 2; // odd-even  → 10
        return 3; // odd-odd → 11
    }

    int maxDifference(string s, int k) {
        int n = s.length();
        int result = INT_MIN;

        // Try all pairs of characters a ≠ b in ['0' to '4']
        for(char a = '0'; a <= '4'; a++){
            for(char b = '0'; b <= '4'; b++){
                if(a == b) continue;

                vector<int> stateMinPrev_a_b(4, INT_MAX);

                int count_a = 0, count_b = 0;
                int prev_a = 0, prev_b = 0;
                int l = -1, r = 0;

                while(r < n){
                    if(s[r] == a) count_a++;
                    if(s[r] == b) count_b++;

                    // Shrink window while maintaining at least k length and constraints
                    while(r - l >= k && count_b - prev_b >= 2 && count_a - prev_a >= 1){
                        int leftState = getState(prev_a, prev_b);
                        stateMinPrev_a_b[leftState] = min(stateMinPrev_a_b[leftState], prev_a - prev_b);

                        l++;
                        if(s[l] == a) prev_a++;
                        if(s[l] == b) prev_b++;
                    }

                    int rightState = getState(count_a, count_b);
                    int bestLeftState = rightState ^ 2; // XOR with 10 (flip a's parity)

                    int bestMinDiffValueLeft = stateMinPrev_a_b[bestLeftState];
                    if(bestMinDiffValueLeft != INT_MAX){
                        result = max(result, (count_a - count_b) - bestMinDiffValueLeft);
                    }

                    r++;
                }
            }
        }

        return result;
    }
};
