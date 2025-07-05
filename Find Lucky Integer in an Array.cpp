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
//T.C: O()
