//T.C : O(n)
class Solution {
public:
    string makeFancyString(string s) {
     int n = s.length();
     string s_new ="";
     int count = 0;
     for(int i=0; i<n; i++){
if(i > 0 && s[i] == s[i-1]){
    count++;
}
else{
    count = 1;
}
     if(count < 3){
        s_new += s[i];
     }
     }
    return s_new; }
};
