//T.C : O(n)
//S.C : O(n)
class Solution {
public:
     int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
  vector<int>left(100001, INT_MAX);//y-same x-changes
  vector<int>right(100001, INT_MIN);//y-same x-changes
  vector<int>top(100001, INT_MIN);//x-same y-changes
  vector<int> bottom(100001, INT_MAX);//x-same y-changes

  for(auto& it : buildings){
    int x = it[0]; int y = it[1];

    left[y] = min(left[y], x);
    right[y] = max(right[y], x);

    bottom[x] = min(bottom[x], y);
    top[x] = max(top[x], y);
  }

int ans = 0;
  for(auto& it : buildings){
    int x = it[0]; int y = it[1];
bool l = left[y] < x;
bool r = right[y] > x;
bool t = top[x] > y;
bool b = bottom[x] < y;

if(l && r && t && b) ans++;
  }

  return ans;
    }
};
