//T.C : O(n*log n + n*k) k ~ =n => O(n^2)
//S.C : O(k)
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& I) {
     sort(I.begin(), I.end(), [](vector<int>& a, vector<int>& b){
        if(a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
     });

     vector<int> result;
for(int i = 0; i < I.size(); i++){
    int start = I[i][0];
    int end = I[i][1];
    
    int count = 0;

     for(int i = result.size() - 1; i >= 0 ; i--){
        if(result[i] >= start && result[i] <= end){
            count++;
            if(count == 2)break;
        }
     }
     if(count == 0){
        result.push_back(end - 1);
        result.push_back(end);
     }
     if(count == 1){
        result.push_back(end);
     }
}
    return result.size();
    }
};

