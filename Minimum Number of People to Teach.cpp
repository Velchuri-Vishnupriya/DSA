//T.C : O(f * n)
//S.C : O(n + m + total_languages)

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
  int count = 0;
  vector<int> vec(n+1 , 0);
  set<int> bad_users;
  for(auto& it : friendships){//O(f)
    int u = it[0] - 1;
    int v = it[1] - 1;

    bool bad = true;
    
   /* This is the bottleneck  of code here n^2 is the worst case to avoid this we can use an unordered set

    for(auto& i : languages[u]){//O(n)
        if(find(languages[v].begin(),languages[v].end(),i) != languages[v].end())
        {bad = false; //O(n)
break;
        }
    } */

    unordered_set<int> setv(languages[v].begin(), languages[v].end());
for (auto& i : languages[u]) {
    if (setv.count(i)) { // O(1) lookup
        bad = false;
        break;
    }
}

    if(!bad) continue;

    //bad_users;
   if(bad_users.find(u) == bad_users.end()){//O(n)
    for(auto& i : languages[u]){
        vec[i] ++;
    }
}

if(bad_users.find(v) == bad_users.end()){
     for(auto& i : languages[v]){
        vec[i] ++;
    }
}

 bad_users.insert(u);
 bad_users.insert(v);
  }
int max_ele = max_element(vec.begin(),vec.end()) - vec.begin();//O(n)

  for(auto& it : bad_users){//O(m)
    if(find(languages[it].begin(),languages[it].end(),max_ele) == languages[it].end()) count++;
  }
    return count;}
};


