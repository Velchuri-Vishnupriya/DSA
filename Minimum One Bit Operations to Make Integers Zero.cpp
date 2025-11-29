//T.C : O(constant)
//S.C : O(constant)
class Solution {
public:
    int minimumOneBitOperations(int n) {
    if(n == 0) return 0;

    vector<long long> F(31,0);
    //F[i] = number of operations to convert a number having only ith bit set
    F[0] = 1; //2^0 = 1 -> 0
    for(int i = 1; i <= 30; i++){
        F[i] = 2*F[i-1] + 1;
    }

    int result = 0;
    int sign = 1;

    for(int i = 30; i >= 0; i--){
        int ith_bit = ((1 << i) & n);
        if(ith_bit){
            result += ((sign == 1) ? F[i] : F[i]*(-1));
            (sign == 1) ? sign = -1 : sign = 1; 
        }
    }
   return result; }
};
