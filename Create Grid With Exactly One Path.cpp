//T.C : O(m*n)
//S.C : O(n)
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result;

        string s0(n,'.');//O(n)
        result.push_back(s0);
        
        string s_i(n,'#');//O(n)
        s_i[n-1]='.';

        for(int i=1; i<m; i++){//O(m-1)
            result.push_back(s_i);//O(n)
        }
    return result;
    }
};
