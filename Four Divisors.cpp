//T.C : O(n*sqrt(maxNum))
class Solution {
public:
int fourDivisorsCheck(int num){
    int sum = 0;
    int count = 0;
    for(int i = 1; i <= sqrt(num); i++){
        int op1 = i;
        int op2 = 0;
        if(num % i == 0){
            op2 = num/i;
        }
        if(op2 > 0){
            op1 == op2 ? count++ : count+=2;
            op1 == op2 ? sum += op1 : sum += (op1 + op2);
        }
        if(count > 4){
            return 0;
        }
        
    }
    return count == 4 ? sum : 0;
}
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for(auto& num : nums){
            result += fourDivisorsCheck(num);
        }
        return result;
    }
};
