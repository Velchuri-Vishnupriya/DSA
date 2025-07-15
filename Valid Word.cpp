//T.C : O(n);
class Solution {
public:
    bool isValid(const string& s) {
   if(s.length() < 3) return false;
   
   bool v = false;
   
   bool c = false;
   
   for(auto& ch : s){
    char C = tolower(ch);

    if(!isalnum(C)) return false;

    if(C=='a'||C=='e'||C=='i'||C=='o'||C=='u') v = true;

    if(!isdigit(C) && !(C=='a'||C=='e'||C=='i'||C=='o'||C=='u')) c = true;
   }
        
        
    return v && c;}
};
