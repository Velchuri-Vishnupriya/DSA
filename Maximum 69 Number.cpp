//Approach - 1
//T.C: O(d) d=number of digits
//S.C: O(d)
class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);   
        for (int i=0; i<str.length(); i++) {
            if (str[i] == '6') {       
                str[i] = '9';      
                break;                 
            }
        }
        return stoi(str);              
    }
};

//Approach - 2 constabnt space
//T.C: O(d)
class Solution {
public:
    int maximum69Number (int num) {
        int original_num = num;
        int pos = -1;
        int place = 0;
        while(num){
            if(num % 10 == 6){
                pos = place;
            }
            num/=10;
            place++;
        }           
        if(pos == -1) return original_num;
        else return original_num + 3*pow(10,pos);  
    }
};
