//Top - Down with Memoization
//Every index is visited once and each index goes d times towards left d times towards right O(n*(d+d))
//T.C : O(n*d)
//S.C : O(n)
class Solution {
public:
int n;
vector<int> t;
int solve(vector<int>& arr, int i, int d){

    if(t[i] != -1)return t[i];

    int result = 1;

    //left
    for(int j=i-1; j >= max(0, i-d); j--){
        if(arr[j] >= arr[i])break;

        result = max(result, 1 + solve(arr, j, d));
    }

    //right
    for(int j=i+1; j <= min(n-1, i+d); j++){
        if(arr[j] >= arr[i])break;

        result = max(result, 1 + solve(arr, j, d));
    }

    return t[i] = result;
}
     int maxJumps(vector<int>& arr, int d) {
      n = arr.size();

      t.resize(n+1, -1);

      int result = 1;
      for(int i=0; i<n; i++){
        result = max(result, solve(arr,i, d));
      }  
      return result;
    }
};

//Bottom-Up
//T.C : O(n*d + nlogn)
//S.C : O(n)
class Solution {
public:
int n;
vector<int> t;
int maxJumps(vector<int>& arr, int d) {
      n = arr.size();

      t.resize(n+1, -1);

      //t[i] = max indices covered if we jump from index i

      vector<pair<int,int>> vec;

      for(int i=0; i<n; i++){
        vec.push_back({arr[i], i});
      }

      sort(begin(vec), end(vec));

      for(auto& it : vec){
        int val = it.first;
        int i = it.second;

        int result = 1;

        //left
        for(int j=i-1; j>=max(0, i-d); j--){
            if(arr[j] >= arr[i]){break;}

            result = max(result, 1 + t[j]);
        }

        //right
        for(int j=i+1; j<=min(n-1, i+d); j++){
            if(arr[j] >= arr[i])break;

            result = max(result, 1 + t[j]);
        }
        t[i] = result;
      }
      return *max_element(begin(t), end(t));
    }
};
