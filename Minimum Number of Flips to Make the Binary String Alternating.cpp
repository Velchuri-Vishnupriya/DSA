//Using Sliding Window
//T.C : O(2*n)~O(n)
//S.C : O(2*n)~O(n)
class Solution {
public:
    int minFlips(auto& s) {
      int n = s.length();

      s = s + s;

      //s1 = "010101..."
      //s2 = "10110..."

      string s1, s2;
      for(int i = 0; i < 2*n; i++){
        s1 += (i%2 ? '0' : '1');
        s2 += (i%2 ? '1' : '0');
      }

      //slifing approach
      int result = INT_MAX;
      int flip1 = 0;
      int flip2 = 0;

      int i = 0;
      int j = 0;

      while(j < 2*n){
        if(s[j] != s1[j])flip1++;
        if(s[j] != s2[j])flip2++;

        if(j-i+1 > n){
            //shrink window from left
            if(s[i] != s1[i])flip1--;
            if(s[i] != s2[i])flip2--;
            i++;
        }

        if(j-i+1 == n){
            result = min({result, flip1, flip2});
        }
        j++;
      }
    return result;}
};

//Using Sliding Window enhanced version
//T.C : O(2*n)~O(n)
//S.C : O(1)
class Solution {
public:
    int minFlips(auto& s) {
      int n = s.length();

     // s = s + s;

      //s1 = "010101..."
      //s2 = "10110..."

      string s1, s2;
      for(int i = 0; i < 2*n; i++){
        s1 += (i%2 ? '0' : '1');
        s2 += (i%2 ? '1' : '0');
      }

      //slifing approach
      int result = INT_MAX;
      int flip1 = 0;
      int flip2 = 0;

      int i = 0;
      int j = 0;

      while(j < 2*n){
        char expected1 = (j % 2) ? '0' : '1';
        char expected2 = (j % 2) ? '1' : '0';
        if(s[j % n] != expected1)flip1++;
        if(s[j % n] != expected2)flip2++;

        if(j-i+1 > n){
            //shrink window from left
            expected1 = (i % 2) ? '0' : '1';
            expected2 = (i % 2) ? '1' : '0';
            if(s[i % n] != expected1)flip1--;
            if(s[i % n] != expected2)flip2--;
            i++;
        }

        if(j-i+1 == n){
            result = min({result, flip1, flip2});
        }
        j++;
      }
    return result;}
};
