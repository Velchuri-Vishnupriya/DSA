//Approach-1 (Brute force) - Time Limit Exceeded due to large constraints
//T.C: O()
//S.C: O(n)

class Solution {
public:
int solve(int left,int right,vector<int>& prime){
    int low=left;
    int high=right;
    int Primes=0;
    while (low <= high) {
  bool  is_prime = true;

    // 0 and 1 are not prime numbers
    if (low == 0 || low == 1) {
      is_prime = false;
    }
 
    for (int i = 2; i <= low/2; ++i) {
      if (low % i == 0) {
        is_prime = false;
        break;
      }
    }
        
    if (is_prime){
        Primes++;
        prime.push_back(low);
    }

    ++low;
  }
  return Primes;
}
    vector<int> closestPrimes(int left, int right) {
    
        vector<int> prime;
        int diff=INT_MAX;
        int primes;
        primes=solve(left,right,prime);
        if(primes<=0 || primes==1) return {-1,-1};
        int j;
        for(int i=1;i<prime.size();i++){
int Diff=prime[i]-prime[i-1];
if(Diff<diff){
    diff=Diff;
    j=i;
}
        }
        return {prime[j-1],prime[j]};  
        }
};
