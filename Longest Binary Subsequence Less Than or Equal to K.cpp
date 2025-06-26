//T.C: O(n)
class Solution {
public:
    int longestSubsequence(string s, int k) {
  int length = 0;
  int power = 0;
  int n = s.length();
  long long value = 0;
  for(int i = n-1; i>=0; i--){
    if(s[i]=='0') length++;
    else{
        if(power<32 && (value + (1LL<<power)<=k)){
            value += (1LL<<power);
            length ++;
        }
    }
    power ++;
  }
  return length;  }
};
