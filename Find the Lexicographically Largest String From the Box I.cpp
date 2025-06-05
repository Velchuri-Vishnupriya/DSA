//T.C: O(n^2)
//S.C: O(1)
class Solution {
public:
    string answerString(string word, int numFriends) {
          if(numFriends == 1) return word;

          int n = word.length();

       int longestPossible = n - (numFriends - 1);

string result = "";

       for(int i=0; i<n; i++){//O(n)
        int canTake = min(longestPossible, n - i);
        result = max(result , word.substr(i,canTake)); //O(n) - substr func takes bigO of n time at worst Case
       }
   return result; }
};
