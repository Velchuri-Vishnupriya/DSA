//Approach-1
//T.C : O((m*n) * s*(m+n)) , where s = arr.size() which is (m*n)
//S.C : O(m*n)
class Solution {
public:
bool checkrow(vector<vector<int>>& mat,int row) {
    for(int col=0;col<mat[0].size();col++){
        if(mat[row][col]>0)return false;}
    return true;
}
bool checkcol(vector<vector<int>>& mat,int col){
    for(int row=0;row<mat.size();row++){
       if(mat[row][col]>0) return false;}
    return true;
}

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();

    unordered_map<int,pair<int,int>> mp;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int val=mat[i][j];
            mp[val]={i,j};
        }
    }

    for(int i=0;i<arr.size();i++){
        int val=arr[i];
        auto[row,col]=mp[val];
        mat[row][col] *= -1;
        if(checkrow(mat,row) || checkcol(mat,col))
        {return i;}
    }
    return -1; 
    }
};

//Approach-2
//T.C : O(m*n)
//S.C : O((m*n) + m + n)
class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();

    unordered_map<int,pair<int,int>> mp;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int val=mat[i][j];
            mp[val]={i,j};
        }
    }

    vector<int> rowcount(m,0) ;//how many painted in row
    vector<int> colcount(n,0); //how many painted in col
    for(int i=0;i<arr.size();i++){
        int val=arr[i];
        auto[row,col]=mp[val];
        rowcount[row]++;
        colcount[col]++;
        if(rowcount[row]==n || colcount[col]==m){return i;}
    }
    return -1; 
    }
};

//Approach - 3 
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();

    unordered_map<int,int> mp;

for(int i=0;i<arr.size();i++){
    int it=arr[i];
    mp[it]=i;
}

int minIndex=INT_MAX;

for(int row=0;row<m;row++){
    int lastindex=INT_MIN;
    for(int col=0;col<n;col++){
        int val=mat[row][val];
        int idx=mp[val];
        lastindex=max
        (lastindex,idx);
    }
    minIndex=min(minIndex,lastindex);
}

for(int col=0;col<n;col++){
    int lastIndex=INT_MIN;
    for(int row=0;row<m;row++){
        int val=mat[row][col];
        int idx=mp[val];
        lastIndex=max(idx,lastIndex);
    }
    minIndex=min(minIndex,lastIndex);
}
    return minIndex; 
    }
};
