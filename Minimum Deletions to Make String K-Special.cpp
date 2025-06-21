//T.C: O(n*log n)
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> res(26,0);
        for(auto& it:word)
        {
            res[it-'a']++;
        }
        int final_change = INT_MAX;
        int cumulative_del = 0;
        sort(begin(res),end(res));
        for(int i=0; i<26;i++){
        int frei = res[i];
        int deleted = cumulative_del;
            for(int j=25;j>=0;j--){
                if(res[j] <= k+res[i]) continue;

                deleted += res[j] - res[i] - k;
        }
        final_change = min(deleted , final_change);
        cumulative_del += frei;
        }
        return final_change;
        }
};
