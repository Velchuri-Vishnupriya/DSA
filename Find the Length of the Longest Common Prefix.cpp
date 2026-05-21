//T.C : O((n+m)*L) n = arr1.size() m = arr2.size() L = avg number of digits
//S.C : O(m*L)
class Solution {
public:

int maxLen = 0;

unordered_set<string> prefixSet;

void computePrefixes(vector<string>& arr2){
    for(auto& s : arr2){//O(m)
        string temp = "";

        for(auto& ch : s){//O(len(s))
            temp+=ch;
            prefixSet.insert(temp);
        }
    }
}   

void solve(string s){
    string temp = "";
    for(auto& ch : s){//O(len(s))
        temp += ch;
        if(prefixSet.find(temp) != prefixSet.end()){//O(1)
            maxLen = max(maxLen, (int)temp.length());
        }
    }
}

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

    vector<string> a1;
    vector<string> a2;

    for(auto& num : arr1){
        a1.push_back(to_string(num));
    }

    for(auto& num : arr2){
        a2.push_back(to_string(num));
    }

    computePrefixes(a2);

    for(auto& s : a1){//O(n)
        solve(s);
    }

    return maxLen;
}
};
