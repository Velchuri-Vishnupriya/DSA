//Using Trie
//(n*l + m)
struct trieNode{
    trieNode* children[26];
    bool isEndOfWord;
    int count;
};
trieNode* getNode(){
    trieNode* newNode=new trieNode();
    newNode->isEndOfWord=false;
    newNode->count=0;
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

void insert(string& word){
    trieNode* pcrawl=root;
    for(char& ch :word){
        int idx=ch-'a';
        if(pcrawl->children[idx]==NULL){
            pcrawl->children[idx]=getNode();
        }
        pcrawl=pcrawl->children[idx];
        pcrawl->count++;
    }
    pcrawl->isEndOfWord=true;
}

int searchPrefixCount(string& pref){
    trieNode* pcrawl=root;
    for(char& ch:pref){
        int idx=ch-'a';
        if(pcrawl->children[idx]==NULL){return 0;}
        pcrawl=pcrawl->children[idx];
    }
    return pcrawl->count;
}
};
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
Trie trie;
for(string &word:words){
    trie.insert(word);
}
    return trie.searchPrefixCount(pref);}
};

//Naive
//O(n*m)
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string& word : words) {
            if (word.find(pref) == 0) {
                count++;
            }
        }
        return count;
    }
};
