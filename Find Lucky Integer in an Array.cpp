//Approach - 1
//T.c: O(n)
class Solution {
public:
    int findLucky(vector<int>& nums) {
        int res = -1;
        vector<int> arr(501,0);
        for(auto& it:nums){
            arr[it]++;
        }
        for(int i=0; i <501; i++){
            if(i==arr[i]) res = i;
        }
        return (res==0 ? -1: res);
    }
};

//Approach - 2
//T.c: O(n)
//S.C: O(1)
class Solution {
public:
    int findLucky(vector<int>& arr) {
     int n= arr.size();

     for(int &num : arr){
        int val = (num & 65535);
     if(val <= n){
        arr[val - 1] += (1<<16); //65536 ,pow(2,16)
     }
}

for(int val = n; val>=1; val--){
    if((arr[val-1]>>16) == val) return val;
}
   return -1;}
};
