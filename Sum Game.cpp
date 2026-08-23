//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool sumGame(string nums) {
        int leftKnownSum = 0;
        int rightKnownSum = 0;

        int leftQnMarkCount = 0;
        int rightQnMarkCount = 0;

        int n = nums.size();

        for (int i = 0; i < n / 2; i++) {

            // Left half
            if (nums[i] == '?') {
                leftQnMarkCount++;
            } else {
                leftKnownSum += nums[i] - '0';
            }

            // Right half
            if (nums[n - 1 - i] == '?') {
                rightQnMarkCount++;
            } else {
                rightKnownSum += nums[n - 1 - i] - '0';
            }
        }

        if ((leftQnMarkCount + rightQnMarkCount) % 2)
            return true;

        return leftKnownSum * 2 + 9 * leftQnMarkCount !=
               rightKnownSum * 2 + 9 * rightQnMarkCount;
    }
};
