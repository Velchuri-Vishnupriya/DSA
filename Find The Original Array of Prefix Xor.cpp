//Approach - 1
//T.C : O(n) - > using an extra array
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr(pref.size());
        arr[0] = pref[0];
        int currentXOR = arr[0];
        for(int i=1; i<pref.size(); i++){
            arr[i] = currentXOR ^ pref[i];
            currentXOR ^= arr[i];
        }
        return arr;
    }
};

//Approach - 2 -> w/o using an extra array
//T.C : O(n)
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        for(int i = n-1; i > 0; i--){
            pref[i] = pref[i-1] ^  pref[i];
        }
        return pref;
    }
};
