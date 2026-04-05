//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool judgeCircle(string moves) {
        int countU = 0;
        int countD = 0;
        int countL = 0;
        int countR = 0;

        for(char ch : moves){
            if(ch == 'U')countU++;
            else if(ch == 'D')countD++;
            else if(ch == 'L')countL++;
            else countR++;
        }

        return (countU == countD) && (countL == countR);
    }
};
