//T.C : O(12*60)~O(1)
//S.C : O(12+60)~O(1)
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> hoursSetBits;
        vector<int> minsSetBits;

        for(int i = 0; i < 12; i++){
            hoursSetBits.push_back(__builtin_popcount(i));
        }

         for(int i = 0; i < 60; i++){
            minsSetBits.push_back(__builtin_popcount(i));
        }

vector<string> ans;

        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 60; j++){
                if(hoursSetBits[i] + minsSetBits[j] == turnedOn)
                {
                    string s = "";
                    s+=(to_string(i));
                    s.push_back(':');
                    if(j<10) s.push_back('0');
                    s+=(to_string(j));
                    ans.push_back(s);
                }
            }
        }
    return ans;
    }
};
