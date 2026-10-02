//T.C : O(4^n)
//S.C : O(2*n)~O(n) 
class Solution {
public:
vector<string> result;
void solve(string curr, int n, int open_brackets){
    if(open_brackets < 0)return;

    if(curr.length() == 2*n)
    {if(open_brackets == 0)
        {
            result.push_back(curr);
        }
        return;
    }

    curr.push_back('(');
    solve(curr, n, open_brackets+1);
    curr.pop_back();
    
    curr.push_back(')');
    solve(curr, n, open_brackets-1);
    curr.pop_back();
}
    vector<string> generateParenthesis(int n) {
        solve("", n, 0);
       return result;
    }
};
