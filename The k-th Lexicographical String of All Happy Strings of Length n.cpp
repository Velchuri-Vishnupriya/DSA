//T.C : O(3*2^n-1)~O(2^n)
//S.C : O(n)
class Solution {
public:
string solve(string curr, int n, int& k){
    if(curr.length() == n){
        k--;
        if(k == 0) return curr;
        else return "";
    }
    for(int i = 0; i < 3; i++){
        char ch = i + 'a';

        if(!curr.empty() && curr.back() == ch)continue;

        curr.push_back(ch);

        string ans = solve(curr, n, k);

        if(ans != "")return ans;

        curr.pop_back();
    }
    return "";
}
    string getHappyString(int n, int k) {
        string curr = "";
   return solve(curr, n, k);
    }
};
