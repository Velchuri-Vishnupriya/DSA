// T.C : O(n)
// S.C : O(n)
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
    //case1 k=1
    if(k == 1){
    int answer = -1;
    unordered_map<int,int> freq;
    for(auto& num:nums){
        freq[num]++;
    }
    for(auto& it:freq){
        if(it.second > 1)continue;
        answer = max(answer, it.first);
    }
    return answer;
    }
    //case2 k=n
    else if(k == n) return *max_element(nums.begin(), nums.end()); 
    //case3 1<k<n
    else{
int count_L = count(nums.begin(), nums.end(), nums[0]);
int count_R = count(nums.begin(), nums.end(), nums[n-1]);
if(count_L < 2 && count_R < 2){
    return max(nums[0], nums[n-1]);
}
if(count_L < 2 && count_R > 1){
    return nums[0];
}
if(count_R < 2 && count_L > 1){
    return nums[n-1];
}
    }
    return -1;
    }
};
