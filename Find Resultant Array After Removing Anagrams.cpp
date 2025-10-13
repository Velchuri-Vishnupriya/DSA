//n = number of words
//m = average (or max) length of each word
//T.C : O(n*m log m)
//S.C : O(m)
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string prev = "";

        for(auto& s:words){//O(n*m log m)
           string s1 = s; //O(m)
            sort(s.begin(), s.end()); //O(m log m)
            if(s != prev){//O(m)
                prev = s;
                result.push_back(s1);
            }
        }
   return result; }
};
