//T.C : O(log n) -> we iterate through the number of  digits of the num 
//S.C : O(1)
class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int idx = s.find_first_not_of('9');
        if(idx != string::npos){
            char ch = s[idx];
            replace(begin(s),end(s),ch,'9');
        }
        string s1 = to_string(num);
        if(s1.length() > 1 && s1[0] == '1'){
            char newCh;
            for(int i=1; i<s1.length();i++){
                if(s1[i]!='0' && s1[i]!='1') {
                    newCh = s1[i]; 
                     replace(begin(s1) , end(s1),newCh ,'0');
                    break;
                    } 
            }
           
        
        }
        else{
            char ch = s1[0];
             replace(begin(s1) , end(s1),ch ,'1');
        }
    return stoi(s) - stoi(s1);}
};
