//O(log n) -> This is because each time we divide by 2(>>1) hence it is equivalent to traversing the total digits of the num 
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0 ;
        while(n > 0){
            if((n&1)!=0) count++;
        n>>=1;}
    return count;}
};
