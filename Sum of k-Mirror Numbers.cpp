//T.C : O(10^D * D) D = log n (no.of digits)
//S.C : O(D) palindrome size
 class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    string convertToBaseK(long long n , int k) {
        string res = "";
        while(n) {
            res += to_string(n % k);
            n /= k;
        }
        reverse(res.begin(), res.end());
        return res; 
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int L = 1; //Creating L length Palindrome

        while(n > 0) {
            int half_length = (L + 1) / 2;

            long long min_num =pow(10, half_length - 1);
            long long max_num = pow(10, half_length) - 1;

            for(int num = min_num; num <= max_num; num++) {
                string first_half = to_string(num);
                string second_half = first_half;
                reverse(begin(second_half), end(second_half));

                if(L % 2 != 0) {
                    first_half += second_half.substr(1);
                } else {
                    first_half += second_half;
                }

                long long pal_num = stoll(first_half);

                string baseK = convertToBaseK(pal_num , k); 
                if(isPalindrome(baseK)) {
                    sum += pal_num;
                    n--;
                    if(n == 0) break;    }
            }
            L++;
        }
        return sum;
    }
};
