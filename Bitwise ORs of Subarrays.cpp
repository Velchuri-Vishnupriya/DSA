//T.C : O(n)
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        unordered_set<int> curr;
        for(int i=0; i<arr.size(); i++){//O(n)
            unordered_set<int> temp;
            temp.insert(arr[i]);
            for(auto it : curr){//O(32) -> At max there can be 32 ele in set
                temp.insert(it | arr[i]);
            }
            curr = temp;
            for(auto& it : curr){
                res.insert(it);
            }
        }
    return res.size();}
};
