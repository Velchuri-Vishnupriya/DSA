//T.C : O(Q*logn)
//S.C : O(n)
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
int n = nums.size();

unordered_map<int, vector<int>> mp;

for(int i=0; i<n; i++){
    mp[nums[i]].push_back(i);
}

vector<int> result;

for(auto& idx : queries){
    int val = nums[idx];
    vector<int>& vec = mp[val];

    if(vec.size() == 1){
        result.push_back(-1);
        continue;
    }

   int pos = lower_bound(begin(vec), end(vec), idx) - begin(vec);
   int res = INT_MAX;

   //right neigbor
   int right = vec[(pos + 1) % vec.size()];
   int straightDist = abs(idx - right);
   int circularDist = n - straightDist;
   res = min({res,straightDist, circularDist});

   //left neigbor
   int left = vec[(pos - 1 + vec.size()) % vec.size()];
   straightDist = abs(idx - left);
   circularDist = n - straightDist;
    res = min({res,straightDist, circularDist});

    result.push_back(res);
}
    return result;
    }
};
