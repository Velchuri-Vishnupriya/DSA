//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int count0 = 0;
int count1 = 0;
int i =0;
int ans = 0;
int n = s.length();
while(i < n){
//count 0's
if(s[i] == '0'){
    count0 = 0;
    while(i < n && s[i] == '0'){
        count0++;
        i++;
    }
    ans += min(count0, count1);
}
//count 1s
if(s[i] == '1'){
    count1 = 0;
    while(i < n && s[i] == '1'){
        count1++;
        i++;
    }
    ans += min(count0, count1);
}
}
return ans;
    }
};
