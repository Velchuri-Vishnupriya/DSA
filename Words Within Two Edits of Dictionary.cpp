//T.C : O(q*d*m) q = queries.size(), d = dictionary.size(), m = q[i]
//S.C : O(1) 
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;

        for(auto& query : queries){
            for(auto& word : dictionary){
                int maxLimit = 0;
                int wordLen = word.length();
                for(int i=0; i<query.size(); i++){
                    if(i < wordLen && query[i] != word[i]){
                        maxLimit++; 
                        if(maxLimit > 2)break;
                        }
                }

                if(maxLimit <= 2){
                    result.push_back(query);
                    break;
                }
            }
        }
    return result;
    }
};
