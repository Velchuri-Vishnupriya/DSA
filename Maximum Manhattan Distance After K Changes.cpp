//T.C : O(n)
class Solution {
public:
    int maxDistance(string s, int k) {
   int cN,cS,cW,cE;
   cN=0; cS=0; cW=0; cE=0;
  int maxMD = 0;
  for(int i=0; i<s.length(); i++){
    if(s[i]=='E') cE++;
    else if(s[i]=='W') cW++;
    else if(s[i]=='N') cN++;
    else cS++;

    int currMD = abs(cW - cE) + abs(cN - cS);
    int steps = i+1;
    int wasted = steps - currMD;

    int extra = 0;
    if(wasted !=0){
        extra = min(2*k, wasted);
    }

    int finalCurrMD = currMD + extra;
    maxMD = max(maxMD , finalCurrMD);
  }
      return maxMD; }
};
