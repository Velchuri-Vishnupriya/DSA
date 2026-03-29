class Solution {
public:
    bool canBeEqual(string s1, string s2) {
int n = s1.length();

if(s1 == s2) return true;

string temp = s1;

/*3 possible cases
0,2 idx swap and check
1,3 idx swap and check
both 0,2 and 1,3 idx swap*/

swap(s1[0], s1[2]);
if(s1 == s2)return true;
swap(s1[0], s1[2]);

swap(s1[1], s1[3]);
if(s1 == s2)return true;

swap(s1[0], s1[2]);
if(s1 == s2)return true;

return false;
}
};
