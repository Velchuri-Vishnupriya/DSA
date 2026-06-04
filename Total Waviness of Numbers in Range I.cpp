//T.C : O((num2-num1+1)*d)
//S.C : O(d)
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total = 0;
        for(int num=num1; num<=num2; num++){
            string s = to_string(num);
            for(int i=1; i<s.length()-1; i++){
                if(s[i] > s[i-1] && s[i] > s[i+1]){
                    total++;
                }
                if(s[i] < s[i-1] && s[i] < s[i+1]){
                    total++;
                }
            }
        }
    return total;
    }
};
