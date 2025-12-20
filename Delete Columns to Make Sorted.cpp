//T.C : O(L*n) L = length of the longest str, n = strs size 
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int toDelete = 0;
        int strlen = strs[0].length();
        for(int i = 0; i < strlen; i++){//O(L)
            char ch = strs[0][i];
            for(int j = 1; j < strs.size(); j++){//O(n)
                    if(strs[j][i] < ch){
                            toDelete++;
                            break;
                        }
                    ch = strs[j][i];
            }
        }
    return toDelete;
    }
};
