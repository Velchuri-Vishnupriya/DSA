//Approach - 1:
//O(10*n) ~ O(n)
class Solution{
public:
string largestGoodInteger(string num) {
for (char d ='9'; d >='0'; --d) {
string target(3, d);
if (num.find(target) != string::npos) {//find func will take O(n) time at worst case
return target;
}
}
return "";
}
};

//Approach - 2
//O(n)
class Solution{
public:
string largestGoodInteger(string num) {
char maxChar ='\0'; // null char, smaller than any
for (int i = 0; i < num.size() - 2; ++i) {
if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
maxChar = max(maxChar, num[i]);
}
}
if (maxChar =='\0') return "";
return string(3, maxChar);
}
};
