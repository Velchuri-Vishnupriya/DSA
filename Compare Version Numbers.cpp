//T.C : O(m + n) m = version1.length n = version2.length
//S.C : O(m + n)
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;

        if(version1 == version2) return 0;

        string num1 = "";
        for(char ch: version1){
            if(ch == '.'){
                v1.push_back(stoi(num1));
                num1 = "";
            }
            else{
                num1+=ch;
            }
        }
        if(!num1.empty()) v1.push_back(stoi(num1));
        num1 = "";

        for(char ch: version2){
            if(ch == '.'){
                v2.push_back(stoi(num1));
                num1 = "";
            }
            else{
                num1+=ch;
            }
        }
        if(!num1.empty()) v2.push_back(stoi(num1));
int n = max(v1.size(), v2.size());
for(int i=0; i<n; i++){
    int a = i < v1.size() ? v1[i] : 0;
    int b = i < v2.size() ? v2[i] : 0;
    if (a < b) return -1;
    if (a > b) return 1;
}
     return 0;}
};
