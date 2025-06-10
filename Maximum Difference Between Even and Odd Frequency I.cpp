//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxDifference(string s) {
        vector<int> vec(26,0); //S.C : O(26)
        for(auto& ch : s ){//O(s.length)
            int i = ch - 'a';
            vec[i]++;
        }
        int odd = INT_MIN;
        int even = INT_MAX;
        for(int i=0; i<26; i++){ //O(26)
if(vec[i] !=0 && vec[i]%2 != 0){odd = max(odd,vec[i]);}
else if (vec[i] !=0 && vec[i]%2 ==0) {even = min(even , vec[i]);}
        }
  return odd - even ;  }
};
