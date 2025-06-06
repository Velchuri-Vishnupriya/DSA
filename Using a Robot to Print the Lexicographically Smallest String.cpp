//T.C : O(n)
//S.C : O(n);

class Solution {
public:
    string robotWithString(string s) {
int n = s.length();

        vector<char> minCharToRight(n);

        minCharToRight[n-1] = s[n-1];
        for(int i = n-2; i>=0; i--){
            minCharToRight[i] = min(s[i],minCharToRight[i+1]);
        }

string t="";
string p="";

int i=0;
while(i<n){ //At max we visit a char in string twice so 2*n which is equivalent to n;
    t.push_back(s[i]);

    char minchar = (i+1 < n) ? minCharToRight[i+1] : s[i];
    while(!t.empty() && t.back() <= minchar){
        p += t.back();
        t.pop_back();
    }
    i++;
}

while(!t.empty()){
    p += t.back();
    t.pop_back();
}
    return p;}
};
