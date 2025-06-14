//T.C : O(log n) ->we iterate through the all the digits of the number
//S.C: O(log n) -> maxVal , minVal;
class Solution {
public:
    int minMaxDifference(int num) {
      string maxVal = to_string(num);
      string minVal = to_string(num);
    
    int idx = maxVal.find_first_not_of('9');
    if(idx != string::npos){
char ch = maxVal[idx];
replace(begin(maxVal),end(maxVal),ch,'9');
    }   

    char ch = minVal[0];
    replace(begin(minVal),end(minVal),ch,'0');

    return stoi(maxVal) - stoi(minVal); }
};
