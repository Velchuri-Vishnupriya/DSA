//Approach - 1
//T.C : O(n*n)
//S.C : O(n)
class Solution {
public:

bool canReach(string s, int minJump, int maxJump) {
int n = s.length();

if(s[n-1] == '1')return false;

vector<int> t(n,0);
t[n-1] = 1;

for(int i = n-2; i >= 0; i--){//O(n)
    if(s[i] == '1')continue;

    for(int j = i + minJump; j <= min(i + maxJump, n-1); j++){
        if(t[j] == 1){//O(maxJump - minJump)
            t[i] = 1;
            break;
        }
    }
}
   return t[0];
}
};
