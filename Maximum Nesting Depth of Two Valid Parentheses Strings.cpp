//T.C : O(n)
class Solution {
public:
    vector<int> maxDepthAfterSplit(auto s) {
int depth = 0;
int n = s.size();
vector<int> result(n);
for(int i=0; i<n; i++){
    if(s[i] == '('){
        depth++;
        result[i] = (depth % 2 == 0) ? 0 : 1;
    }else{
         result[i] = (depth % 2 == 0) ? 0 : 1;
         depth--;       
    }
}
    return result;
    }
};
