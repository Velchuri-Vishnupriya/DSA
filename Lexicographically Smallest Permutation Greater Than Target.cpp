//T.C : O(26*n)~O(n)
//S.C : O(26)~O(1)
class Solution {
public:
string result = "";
bool solve(string curr, vector<int>& count, string& target, int i, bool greater){
    if(i == target.length()){
        if(greater){
            result = curr;
            return true;
        }
        return false;
    }

    for(char ch='a'; ch <= 'z'; ch++){
        if(count[ch-'a'] == 0)continue;

        if(greater == false && ch < target[i])continue;

        //do
        curr.push_back(ch);
        count[ch-'a']--;

        bool isGreater = greater || ch > target[i];

        //explore
        if(solve(curr, count, target, i+1, isGreater))return true;

        //undo
        curr.pop_back();
        count[ch-'a']++;
    }
return false;
}
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26,0);

        for(char& ch : s){
            count[ch-'a']++;
        }

        string curr;

        solve(curr, count, target, 0, false);

        return result;
    }
};
