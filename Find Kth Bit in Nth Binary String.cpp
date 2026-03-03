//T.C : O(n)
//S.C : O(n)
class Solution {
public:
char findKthBit(int n, int k) {
    if(n == 1) return '0';
int length = (1 << n) - 1; //length of the n bit string

if(k < ceil(length/2.0)){
    return findKthBit(n-1, k);
}else if(k == ceil(length/2.0)){
    return '1';
}else{
    char ch = findKthBit(n-1, length - (k-1));
    return (ch == '1') ? '0' : '1';
}
    }
};
