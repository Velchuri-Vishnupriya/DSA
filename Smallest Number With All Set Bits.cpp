//T.C : O(log n) n = size of vector 
//S.C : O(1)
class Solution {
public:
    int smallestNumber(int n) {
       vector<int>vec;
       for(int i = 0; i<10; i++){
        vec.push_back(pow(2,i+1)-1);
       }
       int i = lower_bound(vec.begin(), vec.end(), n) - vec.begin();
       return vec[i];
    }
};
