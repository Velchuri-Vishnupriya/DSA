//Using Math
//T.C: O(1)
//S.C: O(1)
class Solution {
public:
    long long coloredCells(int n) {
     //1^2+0^2 2^2+1^2 3^2+2^2 
long long N=n;
long long n1=N-1;
     return static_cast<long long>((N*N)+(n1*n1));
    }
};

//using a while loop
//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    long long coloredCells(int n) {
     long long count=1;
     int t=1;
     while(t<=n){
        count+=4*(t-1);
        t++;
     }
     return count;
    }
};
