//T.C: O(logn^2) depth of the tree can only go up to the number of digits of the number and to find the number of digits in a number logn is used
//S.C: O(log n) system recurrsion stack space

class Solution {
public:
int Count(long curr, long next, int n){
  int  countnum = 0;

  while(curr <= n){
    countnum += (next - curr);

    curr *= 10;
    next *= 10;

    next = min(next, long(n+1));
  } 
  return countnum; 
}
int findKthNumber(int n,int k){
    int curr = 1;
    k -=  1; //since we start from the first number (1), we need k-1 more numbers

    while(k>0){
        int count = Count(curr, curr+1, n);
        if(count <= k){
            curr++;
            k -= count; //skipping the elements under the curr prefix tree
        } 
        else{
            curr *= 10;
            k -= 1;
        }
    }
    return curr;}
};
