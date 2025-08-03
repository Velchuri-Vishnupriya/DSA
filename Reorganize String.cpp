//T.C : k = no.of unique characters
class Solution {
public:
    typedef pair<int,char> P;
    string reorganizeString(string s) {
        priority_queue<P , vector<P>> pq;
        unordered_map<char,int> mp;
        for(auto& ch : s){//O(n)
            mp[ch]++;
            if (mp[ch] > (s.length() + 1) / 2) return "";
        }
        for(auto& [ch, freq]: mp){//O(k)
            pq.push({freq,ch});
        }
        string res = "";
        P prev = {0, '#'};
        while(!pq.empty()){//O(n * log k)
            auto [f,ch] = pq.top();
            pq.pop();
            res +=ch;
            if(prev.first > 0){
                pq.push(prev);
            }
            prev = {f - 1, ch};
        }
        for(int i = 1; i < res.length(); i++){
            if(res[i] == res[i-1]) return "";
        }
    return res;}
};
