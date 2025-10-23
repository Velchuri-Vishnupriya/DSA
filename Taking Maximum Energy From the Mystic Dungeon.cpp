//Recursion + Memoization 
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int n;
    vector<int> t;
    int solve(vector<int>& energy, int i, int k) {
        if (i >= n)
            return 0;
        if(t[i] != INT_MIN) return t[i];
            return t[i] = energy[i] + solve(energy, i + k, k);
    }

    int maximumEnergy(vector<int>& energy, int k) {
        n = energy.size();
        int result = INT_MIN;
t.assign(n+1, INT_MIN);
        for (int i = 0; i < n; i++) {
            result = max(result, solve(energy, i, k));
        }

        return result;
    }
};

//Bottom - Up
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int result = INT_MIN;
vector<int> t(n, 0);
for(int i = n-1; i >= 0; i--){
if(i + k < n){
    t[i] = energy[i] + t[i+k];
}else{
    t[i] = energy[i];
}
}
    return *max_element(begin(t), end(t));
    }
};
