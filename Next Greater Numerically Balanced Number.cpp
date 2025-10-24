//Approach - 1 (TLE)
//T.C : O(k*d)
//S.C : O(d)
class Solution {
public:
bool isPossible(int x){//O(d)
    string s = to_string(x);
    unordered_map<char, int> mp;
    for(auto& ch : s){
        mp[ch]++;
    }

    for(auto& it : mp){
        int d = it.first - '0';
        int count = it.second;
        if(d != count){
            return false;
        }
    }
    return true;
}
    int nextBeautifulNumber(int n) {//O(k*d)
      int x = n + 1;
      while(true){
        if(isPossible(x)) return x;
        x++;
      }
   return -1; }
};

//Optimized Code
//T.C : O(9^d) d = no.of digits
//S.C : O(1)
class Solution {
public:
    vector<int> digitCount = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int backtrack(int n, int curr, int count) {
        if (count == 0) {
            for (int digit = 0; digit <= 9; digit++) {
                if (digitCount[digit] != 0 && digitCount[digit] != digit)
                    return 0;
            }
            return curr > n ? curr : 0;
        }

        int result = 0;
        for (int digit = 1; digit <= 9; digit++) {
            if (digitCount[digit] > 0 && digitCount[digit] <= count) {
                digitCount[digit]--;                     // Do
                result = backtrack(n, curr * 10 + digit, count - 1);
                digitCount[digit]++;                     // UNDO 
                if (result != 0) return result;          // stop once found
            }
        }

        return result;
    }

    int nextBeautifulNumber(int n) {
        int numDigits = to_string(n).length();
        int result = backtrack(n, 0, numDigits);

        if (result == 0) {
            digitCount = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            result = backtrack(n, 0, numDigits + 1);
        }

        return result;
    }
};
