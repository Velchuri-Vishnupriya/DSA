//T.C : O(entire len of wordList + queries)
//S.C : O(entire len of wordList + queries)
class Solution {
public:
unordered_set<string> exactSet;
unordered_map<string,string> caseMp;
unordered_map<string, string> vowelMp; 
vector<string> result;

string toLower(string s){
  string res = "";
  for(char ch : s){
    ch = tolower(ch);
    res += ch;
  }
  return res;
}
string replaceVowel(string& s){
string res = "";
string vowels = "aeiou";
for(char& ch : s){
    if(vowels.find(ch) != string ::npos){
        res+= '*';
    }
    else{
        res += ch;
    }
}
return res;}

string checkForMatch(string& query){
    if(exactSet.count(query)) return query;

    string lowerCase = toLower(query);
    if(caseMp.count(lowerCase)){
        return caseMp[lowerCase];
    }

    string vowelCase = replaceVowel(lowerCase);
    if(vowelMp.count(vowelCase)){
        return vowelMp[vowelCase];
    }
    return "";
}
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exactSet.clear();
        caseMp.clear();
        vowelMp.clear();
        for(string& s: wordlist){
            exactSet.insert(s);

            string lowerCase = toLower(s);

            if(caseMp.find(lowerCase) == caseMp.end()){
                caseMp[lowerCase] = s;
            }

            string vowelCase = replaceVowel(lowerCase);
            if(vowelMp.find(vowelCase) == vowelMp.end()){
                vowelMp[vowelCase] = s;
            }
        }

        for(string& query: queries){
            result.push_back(checkForMatch(query));
        }
    return result;}
};
