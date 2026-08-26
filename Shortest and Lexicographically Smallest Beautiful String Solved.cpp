//Brute Force
//T.C : O((n^3)
//S.C : O(n)
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        for(int len = k; len <= n; len++){//O(n-len)
            string result = "";
            for(int start = 0; start <= n-len; start++){//O(n-len)
                string temp = s.substr(start, len);
                int ones = 0;
                ones += count(temp.begin(), temp.end(), '1');//O(len)
                if(ones == k && (result.empty() || temp < result)){
                    result = temp;
                }
            }
            if(!result.empty()){
                return result;
            }
        }
    return "";}
};

//Optimal
//Sliding Window
//T.C : O((n^2)
//S.C : O(n)
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int ones = 0;
        string result = "";

        while(j < n){
            if(s[j] == '1')ones++;

            while(ones > k || s[i] == '0'){
                if(s[i]=='1')ones--;
                i++;
            }

            if(ones==k){
                string temp = s.substr(i, j-i+1);
                if(result.empty() || result.length() > j-i+1 ||
                (temp.length() == result.length() && temp < result)){
                    result = temp;
                }
            }
            j++;
        }
return result;
}
};
