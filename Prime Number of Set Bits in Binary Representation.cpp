//T.C : O(n) -> n = right - left + 1
//S.C : O(1)
class Solution{
public:
vector<int> primeNums = {2,3,5,7,11,13,17,19};
bool isPrime(int num){
    for(int num1:primeNums){
        if(num1 == num)return true;
    }
    return false;
}
int countPrimeSetBits(int left, int right) {
       int count = 0;
        for(int i = left; i <= right; i++){
            if(isPrime((__builtin_popcount(i)))) count++;//O(1)
        }

        return count;
    }
};
