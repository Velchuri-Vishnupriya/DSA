//T.C : O(n*L + n*log n)
//S.C : O(n)
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = isActive.size();
        vector<vector<string>> vec;
        for(int i = 0; i < n; i++){//O(n)
            if(isActive[i] == false) continue;

            else if(businessLine[i] != "electronics" && businessLine[i] != "grocery" && businessLine[i] != "pharmacy" && businessLine[i] != "restaurant") continue;

            string code_ = code[i];
            bool validCode = true;
            if(code_=="") continue;
            for(auto& ch : code_){//O(n) ~ worst case
                if(!isalnum(ch) && ch != '_'){ validCode = false;
                break;}
            }
            if(validCode){
                vec.push_back({businessLine[i], code[i]});
            }

        }
        sort(vec.begin(), vec.end());//O(n*log n)

        vector<string> ans;
        for(auto& it : vec){
            ans.push_back(it[1]);
        }
    return ans;}
};
