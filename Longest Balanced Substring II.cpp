//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
int helper(string& s, char ch1, char ch2){
    int n = s.length();
    unordered_map<int,int> diffMap;
    int c1 = 0;
    int c2 = 0;
    int maxL = 0;

    for(int i = 0; i < n; i++){
        if(s[i] != ch1 && s[i] != ch2){
            diffMap.clear();
            c1 = 0;
            c2 = 0;
            continue;
        }
        if(s[i] == ch1)c1++;
        if(s[i] == ch2)c2++;

        if(c1 == c2){
            maxL = max(maxL, c1 + c2);
        }

        int diff = c1 - c2;
        if(diffMap.count(diff)){
            maxL = max(maxL, i - diffMap[diff]);
        }else{
            diffMap[diff] = i;
        }
    }
    return maxL;
}
    int longestBalanced(string& s) {
int n = s.length();
int maxL = 0;

//case-1
int count = 1; //S[0]
for(int i = 1; i < n; i++){
    if(s[i] == s[i-1]) count++;
    else{
        maxL = max(maxL, count);
        count = 1; //
    }
}
maxL = max(maxL, count);

//case-2
maxL = max(maxL, helper(s,'a','c'));
maxL = max(maxL, helper(s,'a','b'));
maxL = max(maxL, helper(s,'b','c'));

//case-3
int countA = 0;
int countB = 0;
int countC = 0;
unordered_map<string,int>diffMap;

for(int i = 0; i < n; i++){
    if(s[i] == 'a')countA++;
    if(s[i] == 'b')countB++;
    if(s[i] == 'c')countC++;

    if(countA == countB && countA == countC){
        maxL = max(maxL, countA + countB + countC);
    }

    int diffAB = countA - countB;
    int diffAC = countA - countC;

    string key = to_string(diffAB) + "_" + to_string(diffAC); //logn

    if(diffMap.count(key)){
        maxL = max(maxL, i - diffMap[key]);
    }else{
        diffMap[key] = i;
    }
}

   return maxL;
    }
};
