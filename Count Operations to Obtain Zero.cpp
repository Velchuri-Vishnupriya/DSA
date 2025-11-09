//T.C : O(log(min(n1,n2)))
class Solution {
public:
    int countOperations(int num1, int num2) {
       int op = 0;
       while(num1 && num2){
        if(num1 <= num2){
            op += num2/num1;
            num2 = num2 % num1;
        }else{
            op += num1/num2;
            num1 = num1 % num2;
        }
       }
    return op;}
};
