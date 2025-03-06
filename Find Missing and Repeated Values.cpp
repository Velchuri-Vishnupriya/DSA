//Approach-1
//T.C: O(n^2)
//S.C: O(n^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
int n=grid.size();
int N=n*n+1;
vector<int> v(N,0);
for(auto it: grid){
    for(auto it1:it){v[it1]++;}
}
vector<int> ans(2);
for(int i=1;i<N;i++){
if(v[i]==0) ans[1]=i;
if(v[i]==2) ans[0]=i;
}
return ans;
    }
};

//using map
//same as Approach-1
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
int N=n*n+1;
unordered_map<int,int> mp;
for(auto it:grid){
    for(auto it1:it){
        mp[it1]++;
    }
}
vector<int> ans(2);
for(int i=1;i<N;i++){
    if(mp[i]==2) ans[0]=i;
  else if(mp[i]==0) ans[1]=i;
}
return ans;
    }
};

//Approach-2-Using Math
//T.C:O(N)
//S.C:O(N)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
int n=grid.size();
long long N=n*n;
long long sqsum=0;
long long SqSum;
long long sum=0;
long long Sum;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        sum+=grid[i][j];
        sqsum+=(grid[i][j]*grid[i][j]);
    }
}
Sum=(N*(N+1))/2;
SqSum=(N*(N+1)*(2*N+1))/6;
int a=((sqsum-SqSum)/(sum-Sum)+(sum-Sum))/2;
int b=((sqsum-SqSum)/(sum-Sum)-(sum-Sum))/2;
return {a,b};
    }
};
