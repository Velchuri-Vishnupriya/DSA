//T.C : O(n)
class Solution {
public:
    vector<string> divideString(string s, int k, char x) {
        int len = s.length();
        vector<string> result;
        for(int i=0; i<len; i+=k){//O(n/k)
        string s1 = s.substr(i,k);//O(k)
        if(s1.length() < k){
            s1.append(k-s1.length(),x);
        }
        result.push_back(s1);
        }
    return result;}
};
