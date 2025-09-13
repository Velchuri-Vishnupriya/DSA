//Approach - 1
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    int maxFreqSum(string s) {
        unordered_map<char,int> vowels;
        unordered_map<char,int> cons;

        for(char& ch : s) {
            if(isVowel(ch)) vowels[ch]++;
            else cons[ch]++;
        } 

        int max_vowel = 0, max_cons = 0;

        if(!vowels.empty()) {
            max_vowel = max_element(
                vowels.begin(), vowels.end(),
                [](const pair<char,int>&a, const pair<char,int>&b){ return a.second < b.second; }
            )->second;
        }

        if(!cons.empty()) {
            max_cons = max_element(
                cons.begin(), cons.end(),
                [](const pair<char,int>&a, const pair<char,int>&b){ return a.second < b.second; }
            )->second;
        }

        return max_vowel + max_cons;
    }
};

//Approach - 2
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
public:
    int maxFreqSum(string s) {
     string vowels = "aeiou";
     int arr[26] = {0};
     int max_vowel = 0, max_cons = 0;

        for(char& ch : s){
            if(vowels.find(ch) != string ::npos){
                max_vowel = max(max_vowel, arr[ch - 'a'] + 1); 
                arr[ch - 'a'] += 1;
            }
            else{
                max_cons = max(max_cons, arr[ch - 'a'] + 1);
                arr[ch - 'a'] += 1;
            }
        } 
        return max_vowel + max_cons;
    }
};
