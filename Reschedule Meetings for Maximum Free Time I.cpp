//T.C : O(n)
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeArray;

        //ith event
        //ith start - (i-1)th ka end = free gap duration

        freeArray.push_back(startTime[0]);

        for(int i=1; i<startTime.size(); i++){
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }

        freeArray.push_back(eventTime - endTime[endTime.size()-1]);

        //sliding Window approach

        int i= 0;
        int j= 0;
        int maxSum = 0;
        int currsum = 0;
        int n = startTime.size();
        int res = INT_MIN;
        while(j < n+1){
    currsum += freeArray[j];

    while(i < n && j - i + 1 > k + 1){
        currsum -= freeArray[i];
        i++;
    }

    res = max(currsum , res);  
    j++; 
}
return res;    
    }
};
