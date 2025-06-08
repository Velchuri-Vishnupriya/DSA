//T.C: O(n*Q*logQ)
//S.C: O(Q)

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
        int Q = queries.size();

        priority_queue<int> maxHeap ; //to store the farthest idx;
        priority_queue<int, vector<int>, greater<int> > past ; //to store the past encountered farthest indexes;

sort(begin(queries), end(queries));              //O(nlogn)

int j=0; //pointing to queries
int usedCount = 0; //how many queries we used

for(int i=0; i<n; i++){                          //O(n)
while(j < Q && queries[j][0] == i){              //O(Q)
    maxHeap.push(queries[j][1]); //we only need farthest idx to be stored in maxHeap so queries[j][1] is enough;                                //O(log Q)
j++; 
}
//First we check if we can impact the current i from any past queries endings
nums[i] -= past.size();

while(nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i){   //O(QlogQ)
int ending = maxHeap.top();
maxHeap.pop();
past.push(ending);
usedCount ++;
nums[i]--;
}

if(nums[i] > 0) {
    return -1;
}
//clear out past indices which are outdated
while(!past.empty() && past.top() <= i){ //O(Q logQ)
    past.pop();
}
}
//O(n* (QlogQ*3)) = O(n*Q*logQ)
    return Q - usedCount;
}
};
