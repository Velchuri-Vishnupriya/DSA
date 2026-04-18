//Approach - 1
//T.C : O(d) d = num of digits
//S.C : O(d)
class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(begin(s), end(s));
        int reverseNum = stoi(s);
        return abs(reverseNum - n);
    }
};

//Approach - 2
// T.C : O(d)
//S.C : O(1)
class Solution {
public:
    int mirrorDistance(int n) {
        int original = n;

        int d = log10(n) + 1;
        int mul = pow(10, d - 1);

        int revNum = 0;

        while (n) {
            int rem = n % 10;
            revNum += rem * mul;
            mul /= 10;
            n /= 10;
        }

        return abs(revNum - original);
    }
};
