//Approach 1 - Using BackTracking
//T.S: O(n!)
//S.C: O(n*n!)+O(n)

class Solution {
public:
int n;
void solve (string tiles,vector<bool> &used,unordered_set<string> &st,string &curr){
    st.insert(curr);
    for(int i=0;i<n;i++){
        if(used[i]==true) continue;
     
            used[i]=true;
            curr.push_back(tiles[i]);

            solve(tiles,used,st,curr);
      
        used[i]=false;
        curr.pop_back();
    }
}
    int numTilePossibilities(string tiles) {
        n=tiles.length();
        unordered_set<string> st;
        vector<bool> used(n,false);
        string curr="";
        solve(tiles,used,st,curr);
        return st.size()-1;
    }
};

//Approach 2 Using count of characters + backtracking)
//T.C : O(n!)
//S.C : O(n), total possible sequences = n! and each having n length
class Solution {
public:
int n;
void solve (vector<char>& vec)
{
    n++;
    for(int pos=0;pos<26;pos++){
        if(vec[pos]==0) continue;

        vec[pos]--;

        solve(vec);

        vec[pos]++;
    }
}
    int numTilePossibilities(string tiles) {
       n=0;
       vector<char> vec (26,0);
for(char c: tiles){
    vec[c-'A']++;
}
solve(vec);
       return n-1;
    }
};
