//Approach-1 (Gives time limit exceeded for larger query values)
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    int n=queries.size();
    vector<int> result(n);
   unordered_map<int,int> mp;   
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        int sum=0;
    int x=queries[i][0]; 
        int y=queries[i][1];
        st.insert(y);
        mp[x]=y;
        for(auto& it:mp){
            if(it.second !=0)st.insert(it.second);
        }
        result[i]=st.size();
        st.clear();
    }
    return result;
    }
};

//Approach-2
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
   unordered_map<int,int> ball;
   unordered_map<int,int> color;
   int n=queries.size();
   vector<int> result(n);
   for(int i=0;i<=limit;i++){
int x=queries[i][0]; int y=queries[i][1];
if(ball.count(x)){
   int prev=ball[x];
    color[prev]--;
    if(color[prev]==0) color.erase(prev);
}
   ball[x]=y;
    color[y]++;
    result[i]=color.size();
   }
  return result;  }
};
