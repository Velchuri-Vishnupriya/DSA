//TLE
//T.C: O(n.days)
class Solution {
    public:
        int countDays(int days, vector<vector<int>> &nums) {
            int offdays=0;
       vector<bool> Days(days+1,false);
       for(vector<int>& it: nums){
int start=it[0];
int end=it[1];
for(int i=start;i<=end;i++){
    Days[i]=true;
}
       }
    for(int i=1;i<days+1;i++){
        if(Days[i]==false) offdays++;
    } 
    return offdays;}
};

//Approach-2
//T.C: O(n)
//S.C:O(1)
class Solution {
    public:
        int countDays(int days, vector<vector<int>> &nums) {int n=nums.size();

        sort(begin(nums),end(nums));

        int result=0;
        int start=0;
        int end=0;

        for(auto &meet:nums){
if(meet[0]>end){
    result+=meet[0]-end-1;
}
end=max(end,meet[1]);
        }
     if(days>end) result+= days-end;
     return result;       
      }
};
