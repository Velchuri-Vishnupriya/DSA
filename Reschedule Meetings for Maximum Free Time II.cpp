//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxFreeTime(int endTime, vector<int>& ST, vector<int>& ET) {
       vector<int> freeArray; //store durations of free gaps

       //ith event
       //ith start - (i - 1)th ka end = free gap
       freeArray.push_back(ST[0]);

       for(int i = 1; i < ST.size(); i++){
        freeArray.push_back(ST[i] - ET[i - 1]);
       }

       freeArray.push_back(endTime - ET[ET.size() - 1]);
    
    int n = freeArray.size();
    vector<int> maxRightFree(n , 0);
    vector<int> maxLeftFree(n , 0);

    for(int i = n -2; i >= 0; i--){
        maxRightFree[i] = max(maxRightFree[i+1], freeArray[i+1]);
    }

     for(int i = 1; i < n; i++){
        maxLeftFree[i] = max(maxLeftFree[i-1], freeArray[i-1]);
    }

int result = 0;
//iterating on freearray
for(int i = 1; i < n; i++){
    int currEventTime = ET[i-1] - ST[i-1]; //duration of the event at the ith idx;

    //case 1 Moving completely out
    if(currEventTime <= max(maxLeftFree[i-1], maxRightFree[i])){
        result = max(result, freeArray[i-1] + currEventTime + freeArray[i]);
    }
    //case 2 shift left or right
result = max(result, freeArray[i-1] + freeArray[i]);
}
return result;
    }
};
