//T.C :O(N)
//S.C :O(1)
class Solution {
public:
    int minOperations(auto& s) {
       int n = s.size();

       if(is_sorted(begin(s), end(s)))return 0;//O(N)
       
       if(n == 2)return -1;

       char min_char=*min_element(begin(s), end(s));//O(N)
       char max_char=*max_element(begin(s), end(s));//O(N)

       if(s[0] == min_char || s[n-1] == max_char)return 1;

       char max_mid =*max_element(begin(s)+1, end(s)-1);//O(N)
       char min_mid =*min_element(begin(s)+1, end(s)-1);//O(N)

       if(s[0] > max_mid && s[n-1] < min_mid)return 3;
       else return 2;
    }
};
