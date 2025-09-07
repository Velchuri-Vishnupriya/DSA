//T.C : O(n)
class Solution {
public:
    vector<int> sumZero(int n) {
        //7 -> -1 1 2 -2 3 -3 0 7/2=3
        //9 -> 9/2 = 4          -4 4
        vector<int> result;
        if(n%2 !=0) result.push_back(0);
        int N = n/2;
        for(int i=1; i<=N; i++){
            result.push_back(i);
            result.push_back(-i);
        }
    return result;}
};
