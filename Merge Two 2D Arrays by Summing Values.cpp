//Using on-ordered map
//T.S: O((n+m )+NlogN) --N-size of result array
//S.C: O(2*(n+m))

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i=0;
        int j=0;
         vector<vector<int>> result;
int n=nums1.size();
int m=nums2.size();
unordered_map<int,int> mp;
for(int i=0;i<n;i++){
    int id=nums1[i][0];
    int va=nums1[i][1];
    mp[id]+=va;
}

for(int i=0;i<m;i++){
    int id=nums2[i][0];
    int va=nums2[i][1];
    mp[id]+=va;
}

for(auto it:mp){
    int id=it.first;
    int va=it.second;
    result.push_back({id,va});
}

sort(begin(result),end(result));

return result;
    }
};

//Using ordered map
//T.S: O(n+m)
//S.C: O(2*(n+m))

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i=0;
        int j=0;
         vector<vector<int>> result;
int n=nums1.size();
int m=nums2.size();
map<int,int> mp;
for(int i=0;i<n;i++){
    int id=nums1[i][0];
    int va=nums1[i][1];
    mp[id]+=va;
}

for(int i=0;i<m;i++){
    int id=nums2[i][0];
    int va=nums2[i][1];
    mp[id]+=va;
}

for(auto it:mp){
    int id=it.first;
    int va=it.second;
    result.push_back({id,va});
}

return result;
    }
};

//Using Two pointer
//T.S:O(n+m)
//S.C: O(1)

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i=0;
        int j=0;
         vector<vector<int>> result;
int n=nums1.size();
int m=nums2.size();
while(i<n && j<m){
    if(nums1[i][0]<nums2[j][0]){
        result.push_back(nums1[i]);
    i++;}
    else if(nums1[i][0]>nums2[j][0]){
        result.push_back(nums2[j]);
         j++;
    }
    else{
        result.push_back({nums1[i][0],nums1[i][1]+nums2[j][1]});
        i++;
        j++;
    }
}
while(i<n){
    result.push_back(nums1[i]);
    i++;
}

while(j<m){
    result.push_back(nums2[j]);
    j++;
}
return result;
    }
};
