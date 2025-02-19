//Brute Force
//T.C : O((n+1)! * n)
class Solution {
public:
bool patternmatch(string &num,string pattern)
  {
    for(int i=0;i<pattern.length();i++){
        if(pattern[i]=='I' && num[i]>num[i+1] || pattern[i]=='D' && num[i]< num[i+1] ) return false;

    }
    return true;
  }  string smallestNumber(string pattern) {
        int n=pattern.length();
        string num="";
        for(int i=1;i<=n+1;i++){
            num.push_back(i+'0');
        }
        while(!patternmatch(num,pattern)){
            next_permutation(begin(num),end(num));
        }
        return num;
    }
};

//Using stack
//T.C : O(n)
//S.C : (n)
class Solution {
public:
  string smallestNumber(string pattern) {
        int n=pattern.length();
        string num="";
     stack<char> st;
     int cnt=1;
     for(int i=0;i<=n;i++){
        st.push(cnt+'0');
       cnt++;

       if(i==n || pattern[i]=='I'){
        while(!st.empty()){
            num.push_back(st.top());
            st.pop();
        }
       }
     }
     return num;
    }
};

//using backtracking
//T.S: O((n+1)! *n )
//S.C: O(N+10
bool solve(string& pattern, vector<int>& res, vector<bool>& used, int idx) {
    if (idx == pattern.size() + 1)  // Base case: all numbers are placed
        return true;

    for (int num = 1; num <= pattern.size() + 1; num++) {  
        if (used[num]) continue;  // Skip used numbers

        if (idx == 0 || 
           (pattern[idx - 1] == 'I' && res[idx - 1] < num) || 
           (pattern[idx - 1] == 'D' && res[idx - 1] > num)) {

            res[idx] = num;        // Place the number
            used[num] = true;      // Mark as used

            if (solve(pattern, res, used, idx + 1)) 
                return true;

            used[num] = false;     // Backtrack
            res[idx] = 0;          // Reset res[idx]
        }
    }
    return false;
}

