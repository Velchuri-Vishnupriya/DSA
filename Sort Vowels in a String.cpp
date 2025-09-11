//Approach - 1
//T.C : O(n*log n)
//S.C : O(n)
class Solution {
public:
typedef pair<char,int> P;
    string sortVowels(string s) {
        //set<char> st;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<char> vowels;
        vowels = {'a','e','i','o','u','A','E','I','O','U'};
        string t;
        int i=0;
        for(auto& ch : s){//O(n)
            if(find(vowels.begin(), vowels.end(), ch) == vowels.end()){//constant
                t+=ch;
            }
            else{
                t+='_';
                pq.push({ch,i});//O(log n)
            }
            i++;
        }

       if(pq.empty()) return t;
       
       for(int i=0; i<t.length(); i++){//O(n)
        if(t[i] == '_'){
            auto& val = pq.top();//O(1)
            char vowel = val.first;
            pq.pop();//O(log n)
            t[i]=vowel;
        }
       }
        return t;
        }
    
};

//Aprroach - 2
//T.C : O(n*log n)
//S.C : O(n)
class Solution {
public:
vector<char> vec = {'A','E','I','O', 'U', 'a', 'e','i','o','u'};

bool isVowel(char ch){
    if(find(vec.begin(), vec.end(), ch) != vec.end()) return true;

    return false;
}
    string sortVowels(string s) {
      string temp;

    for(char& ch : s){
        if(isVowel(ch)){
            temp.push_back(ch);
        }
    }
    sort(temp.begin(),temp.end());
    int j = 0;
    for(int i = 0; i<s.length(); i++){
        if(isVowel(s[i])) {s[i] = temp[j];
        j++;}
    }
        return s;}
    
};

//Approach - 3
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
vector<char> vec = {'A','E','I','O', 'U', 'a', 'e','i','o','u'};

bool isVowel(char ch)
{
    if(find(vec.begin(), vec.end(), ch) != vec.end()) return true;

    return false;
}

string sortVowels(string s) {
    unordered_map<char, int>mp;

    for(char& ch: s){
        if(isVowel(ch)){
            mp[ch]++;
        }
    }

    string temp = "AEIOUaeiou";
    int j = 0;

    for(int i=0; i<s.length(); i++){//O(n)
        if(isVowel(s[i])){
            while(mp[temp[j]] == 0){//overall it runs for O(n)
                j++;
            }

            s[i] = temp[j];
            mp[temp[j]]--;
        }
    }
    return s; 
    }
    
};
