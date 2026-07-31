//T.C : O(n)
//S.C : O(26)~O(1)
class Solution {
public:
int minimumPushes(string word) {
unordered_map<char,int> freq;

for(auto& ch : word){//O(n)
    freq[ch]++;
}

vector<int> vec;

for(auto& it : freq){//O(26) there are only 26 chars
    vec.push_back(it.second);
}

sort(vec.begin(), vec.end(), [](int& a, int& b){
    return a > b;
});//O(26log(26))
int total = 0;
for(int i=0; i<vec.size(); i++){//O(26)
   int push = i/8 + 1;
   total += vec[i]*push; 
}
return total;
}
};
