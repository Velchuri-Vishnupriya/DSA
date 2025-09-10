//Top - down with memoization
//T.C : O(n*(forget - delay))
//S.C : O(n)
class Solution {
public:
int M = 1e9 + 7;
vector<int> t;
int solve(int day, int delay, int forget) {
    if (day == 1) return 1;
if(t[day] != -1) return t[day];
    long long result = 0;
    for (int prev = day - forget + 1; prev <= day - delay; prev++) {
        if (prev >= 1) {
            result = (result + solve(prev, delay, forget)) % M;
        }
    }
    return t[day] = (int)result;
}

    int peopleAwareOfSecret(int n, int delay, int forget) {
        t.assign(n+1,-1);
        int total = 0;
        for(int day = n - forget + 1; day <= n; day++){
            total = (total + solve(day, delay, forget)) % M;
        }
    return total;
    }
};

//Bottom - Up 
//T.C : O(n^2)
class Solution {
public:
int M = 1e9 + 7;
vector<int> t;
int peopleAwareOfSecret(int n, int delay, int forget) {
       t.assign(n+1, 0);
       t[1] = 1;
       long long  count = 0;
       for(int day = 2; day <= n; day++){
        for(int prev = day - forget + 1; prev <= day - delay; prev++){
            if(prev <= 0){
                continue;
            }
count = (count + t[prev]) % M;
        } 
      t[day] = (int)count;
      count = 0;
       }
       
       int result = 0;
       for(int day = n-forget+1; day <= n; day++){
        result = (result + t[day]) % M;
       }
    return result;
    }
};

//Bottom - Up - more optimized version
//T.C : O(n)
class Solution {
public:
int M = 1e9 + 7;
vector<int> t;
int peopleAwareOfSecret(int n, int delay, int forget) {
       t.assign(n+1, 0);
       t[1] = 1;
       long long  count = 0;
       for(int day = 2; day <= n; day++){
        if(!(day < delay)) count = (count + t[day - delay]) % M ;
        if(!(day < forget)) count =(count - t[day - forget] + M) % M;
        t[day] = count;
       }
       
       int result = 0;
       for(int day = n-forget+1; day <= n; day++){
        result = (result + t[day]) % M;
       }
    return result;
    }
};
