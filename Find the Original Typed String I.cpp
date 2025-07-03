 //T.C : O(n)
class Solution {
public:
    int possibleStringCount(string s) {
     int res = 1;
     int n = s.length();
     for(int i=1;i<n;i++){
        if(s[i]==s[i-1])res++;
     }
     return res;
    }
};
