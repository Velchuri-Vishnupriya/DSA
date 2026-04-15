//T.C : O(2*n) ~ O(n)
//S.C : O(1)
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
  int result = INT_MAX;

  int n = words.size();

if(words[startIndex] == target)return 0;
  //right traversal;
 int i = startIndex + 1;
 while(i != startIndex){
    if(words[i] == target){
        result = min(result, abs(i - startIndex));
    }
    i = (i + 1) % n;
 }

  
  //left traversal
  i = (startIndex - 1 + n) % n;
  while(i != startIndex){
     if(words[i] == target){
        result = min(result, n - abs(i - startIndex));
    }
    i = (i - 1 + n) % n;
  }
    return result == INT_MAX ? -1 : result;
    }
};
