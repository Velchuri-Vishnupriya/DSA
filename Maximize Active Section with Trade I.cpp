//T.C: O(n)
//S.C: O(n)
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> inactiveBlocks;
        int count0 = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '1')continue;
            else{
                //count countinous zeros
                while(i<s.length() && s[i] != '1'){
                    count0++;
                    i++;
                }
                i--;
                inactiveBlocks.push_back(count0);
                count0 = 0;
            }
        }
        int total0 = accumulate(begin(inactiveBlocks), end(inactiveBlocks),0);
        int total1 = s.length() - total0;
        int M = 0;
        for(int i=1; i<inactiveBlocks.size(); i++){
            M = max(M, inactiveBlocks[i] + inactiveBlocks[i-1]);
        }
        return M + total1;
    }
};
