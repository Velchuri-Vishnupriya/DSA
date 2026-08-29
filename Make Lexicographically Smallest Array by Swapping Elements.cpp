//Brute Force
//T.C : more than O(n^2)
//S.C : O(1)
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        for(int i=0; i<n; i++){

            while(true){
            int smallValue = nums[i];
            int idx = -1;
            for(int j=i+1; j<n; j++){
                if(abs(nums[i] - nums[j]) <= limit){
                    if(nums[j] < smallValue){
                        smallValue = nums[j];
                        idx = j;
                    }
                }
            }

            if(idx != -1){
                swap(nums[i], nums[idx]);
            }else{
                break;
            }
            }
        }
        return nums;
    }
};

//Optimal
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> vec = nums;
        //sort the vec
        sort(begin(vec), end(vec));//O(nlogn)

        int groupNum=0;
        unordered_map<int,int> numToGroup;
        numToGroup[vec[0]] = groupNum;

        unordered_map<int, list<int>> groupToList; //cpp implements list as <-> double linked list and every operation is done in O(1)
        groupToList[groupNum].push_back(vec[0]);

        for(int i=1; i<n; i++){//O(n)
            if(abs(vec[i] - vec[i-1]) > limit){
                groupNum++;
            }
            numToGroup[vec[i]]=groupNum;//O(1)
            groupToList[groupNum].push_back(vec[i]);//O(1)
        }

        //building the answer -> merging the groups
        vector<int> result(n);

        for(int i=0; i<n; i++){//O(n)
            int num = nums[i];
            int group = numToGroup[num];
            //smallest Available number in this group
            result[i] = *groupToList[group].begin();
            groupToList[group].pop_front();
        }
        return result;
}
};
