//Brute force using find func
class Solution {
public:
  bool check(string s1,string s2){
        return(s1.find(s2)==0 && s1.rfind(s2)==s1.length()-s2.length());
     } 

    int countPrefixSuffixPairs(vector<string>& words) {
   int n=words.size();
   int count=0;
   for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(words[i].length()>words[j].length()) continue;
string s1=words[j];
string s2=words[i];
if(check(s1,s2)) {count+=1;}
    }
   }
return count;
    }
};

//brute force using substring
class Solution {
public:
  bool check(string s1,string s2){
        return(s1.substr(0,s2.length())==s2 && s1.substr(s1.length()-s2.length(),s2.length())==s2);
     } 

    int countPrefixSuffixPairs(vector<string>& words) {
   int n=words.size();
   int count=0;
   for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(words[i].length()>words[j].length()) continue;
string s1=words[j];
string s2=words[i];
if(check(s1,s2)) {count+=1;}
    }
   }
return count;
    }
};

//Using Trie
struct trieNode{
    trieNode* children[26];
    bool isEndOfWord;
};

trieNode* getNode(){
    trieNode* newNode=new trieNode();
    newNode->isEndOfWord=false;
    for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
    }
    return newNode;
}

class Trie{
    public:
    trieNode* root;

    Trie(){
        root=getNode();
    }

void insert(string word){
    trieNode* pcrawl=root;
    for(int i=0;i<word.length();i++){
        int idx=word[i]-'a';
        if(pcrawl->children[idx]==NULL){
            pcrawl->children[idx]=getNode();
        }
        pcrawl=pcrawl->children[idx];
    }
    pcrawl->isEndOfWord=true;
}

bool search(string word){
    trieNode* pcrawl=root;
    for(char& ch:word){
        int idx=ch-'a';
        if(pcrawl->children[idx]==NULL) return false;
        pcrawl=pcrawl->children[idx];
    }
    return true;
}
};

class Solution{
    public:
    int countPrefixSuffixPairs(vector<string>& words){
        int n=words.size();
        int count=0;
        for(int j=0;j<n;j++){
            Trie prefix;
            Trie suffix;
            prefix.insert(words[j]);
            string reversed=words[j];
            reverse(begin(reversed),end(reversed));
            suffix.insert(reversed);
            for(int i=0;i<j;i++){
                if(words[i].length()>words[j].length()) continue;
                string rev=words[i];
                reverse(begin(rev),end(rev));
                if(prefix.search(words[i])==true && 
                suffix.search(rev)==true) {count++;}
            }
        }
        return count;
    }
};
