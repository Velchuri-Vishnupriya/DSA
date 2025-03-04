//Approach-1
//T.S:
//S.C:

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int p=0;
       while(pow(3,p) <= n){p++;}
       while(n>0){
        if(n>=pow(3,p)){
            n-=pow(3,p);
        }
        if(n>=pow(3,p)) return false;
        p--;
       } 
       return true;
    }
};

//Approach-2
//
//

class Solution {
public:
    bool checkPowersOfThree(int n) {
  while(n>0){
    if(n%3>=2) return false;
    n=n/3;
  }
       return true;
    }

//Approach-3

class Solution {
public:
bool solve(int n,int p){
    if(n==0) return true;
    if(pow(3,p)>n) return false;
    bool take_p=solve(n-pow(3,p),p+1);
    bool nottake_p=solve(n,p+1);

    return take_p || nottake_p;
}
    bool checkPowersOfThree(int n) {
return solve(n,0);
    }
};
};
