//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mp; //val-rank
        vector<int> vec = arr;
        sort(begin(vec), end(vec));
        int n=arr.size();
        int rank=1;
        for(int i=0; i<n; i++){
            if(i!=0 && vec[i] == vec[i-1]){
                continue;
            }
            mp[vec[i]]=rank;
            rank++;
        }
        for(int i=0; i<n; i++){
            rank = mp[arr[i]];
            vec[i]=rank;
        }
    return vec;
    }
};
