class Solution {
public:
bool isSubset(vector<int>& freq2,){}
    vector<string> wordSubsets(vector<string>& mainWords,
     vector<string>& requiredWords) {
       vector<string> result;
       vector<int> freq2(26);

       for(string &word: requiredWords){
int temp[26]={0};

for(char &ch:word){
    temp[ch-'a']++;
    freq2[ch-'a']=max(freq[ch-'a'],temp[ch-'a']);
}
       }

       for(string& word: mainWords){
        vector<int> temp(26,0);
        for(char &ch:word){temp[ch-'a']++;}
        if(isSubset(freq2.temp)==true){
            result.push_back(word);
        }
       }
return result;
    }
};
