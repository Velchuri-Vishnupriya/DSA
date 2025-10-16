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

//Approach - 2
//n = number of words
//m = average (or max) length of each word
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
bool isAnagram(string s1, string s2){//O(m)
    vector<int> arr(26,0);

    for(int i = 0; i < s1.length(); i++){
        arr[s1[i] - 'a']++;
    }

    for(int i = 0; i < s2.length(); i++){
        arr[s2[i] - 'a']--;
    }

    for(int i = 0; i < 26; i++){
        if(arr[i] != 0) return false;
    }
    return true;
}
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        result.push_back(words[0]);

       int n = words.size();

       for(int i = 1; i < n; i++){//O(n)
        if(!isAnagram(result.back(), words[i])) result.push_back(words[i]); //O(m)
       }
   return result; }
};

