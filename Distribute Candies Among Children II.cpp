Approach - 1
//T.C: O(limit^3) - in the worst case;
//S.C: O(1) - the satck dpeth doesn't reach beyond 4 <=4 

#define ll long long 
class solution {
public:
int solve(int countchild, int n, int limit){
if(countchild == 3) return n==0;
int ways =0;
for(int assign =0; int assign<=min(n,limit); assign++){
ways += solve(countchild + 1, n-assign, limit);
}
ll distributeCandies(int n,int limit){
return solve(0,n,limit);
}
}

Approach - 2
//T.C: O(n^3)
//S.C: O(1);
#define ll long long
class Solution {
public:
ll distributeCandies(int n, int limit) {
       //3 children = ch1, ch2, ch3;
       ll ways = 0;
       for(int ch1=0 ;ch1<=min(n,limit); ch1++){
        for(int ch2=0; ch2<=min(n-ch1,limit); ch2++){
            for(int ch3=0; ch3<=min(n-ch1-ch2,limit);ch3++){
                if(ch3+ch2+ch1==n) ways++;
            }
        }
       }
   return ways; }
};

//Approach - 3
//T.C: O(n^3)
//S.C: O(1)
#define ll long long
class Solution {
public:
ll distributeCandies(int n, int limit) {
       //3 children = ch1, ch2, ch3;
       ll ways = 0;
       for(int ch1=0 ;ch1<=min(n,limit); ch1++){
        for(int ch2=0; ch2<=min(n-ch1,limit); ch2++){
            for(int ch3=0; ch3<=min(n-ch1-ch2,limit);ch3++){
                if(ch3+ch2+ch1==n) ways++;
            }
        }
       }
   return ways; }
};

//Approach - 3;
//T.C: O(n^2);
//S.C: O(1);
#define ll long long
class Solution {
public:
ll distributeCandies(int n, int limit) {
       //3 children = ch1, ch2, ch3;
       ll ways = 0;
       for(int ch1=0 ;ch1<=min(n,limit); ch1++){
        for(int ch2=0; ch2<=min(n-ch1,limit); ch2++){
           int ch3 = min(n-ch1-ch2,limit);
                if(ch3+ch2+ch1==n) ways++;
            
        }
       }
   return ways; }
};

//Approach-4;
//T.C:O(n);
//S.C: O(1);
#define ll long long
class Solution {
public:
ll distributeCandies(int n, int limit) {
      ll ways = 0;
      int min1 = max(0,n - 2*limit);
      int max1 = min(n,limit);
      for(int i=min1; i<=max1; i++){
        //ch1 = i;
        //n-i are left
   //ch2 ch3
   //2 children case
   int N = n - i;
   int Max = min(N,limit);
   int Min = max(0,N - limit);
   ways += (ll)abs(Max - Min) + 1;
      }
   return ways;      }
};
