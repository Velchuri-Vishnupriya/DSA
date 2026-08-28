//T.C : O(n/2*26)~O(n)
//T.C : O(n)
class Solution {
public:
char midChar = '$';
int halfLen = 0;
string result = "";
bool solve(string& curr, vector<int>& count, string& target, int i, bool greater){
    if(curr.length() == halfLen){
        string candidate = curr;
        string rightHalf = curr;
        reverse(rightHalf.begin(), rightHalf.end());
        if(midChar!= '$'){
            candidate += midChar;
        }
        candidate += rightHalf;
        if(candidate > target){
            result = candidate;
            return true;
        }
        return false;
    }

    for(int c=0; c<26; c++){
        if(count[c] == 0)continue;
        if(greater == false && c + 'a' < target[i])continue;

        //do
        curr.push_back(c+'a');
        count[c]--;

        //explore
        bool isGreater = greater || c+'a' > target[i];
        if(solve(curr, count, target, i+1, isGreater))return true;

        //undo
        curr.pop_back();
        count[c]++;
    }
    return false;
}   
string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26,0);

        for(char&ch : s){
            count[ch-'a']++;
        }

        int oddCount = 0;
        
        for(int c=0; c<26; c++){
            if(count[c]%2 == 1){
                oddCount++;
                midChar = c + 'a';
            }
            if(oddCount > 1)return "";
            count[c]/=2;
        }

        halfLen = n/2;
        string curr = "";
        solve(curr, count, target,0,false);
        return result;
    }
};
