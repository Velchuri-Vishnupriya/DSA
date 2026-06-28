//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int n = arr.size();
        arr[0]=1;

        for(int i=1; i<n; i++){
            arr[i] = min(arr[i], arr[i-1]+1);
        }
        return arr[n-1];
    }
};
