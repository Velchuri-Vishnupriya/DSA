//T.C: O(n*logn)
//S.C: O(n)
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(begin(events),end(events)); //n*logn

priority_queue<int, vector<int>, greater<int>> pq;
        int day = events[0][0];
        int i = 0;
        int count = 0; //store the num of events attended

        while(!pq.empty() || i<n){ //push & pop takes log(n) time we visit each element only twice once while pushing and the other time to pop 2 times n*logn op 

if(pq.empty()){
    day = events[i][0];
}

while(i<n && events[i][0]==day){
    pq.push(events[i][1]);
    i++;
}
    if(!pq.empty()){
        pq.pop();
        count++;
    }    
    day++;

    //skip those events whose enDay < day eg((3,4),(4,4) are there we pick 3,4 and 4,4 is left in pq but now the day is incrimented to 5 so 4,4 is of no use hence we pop it)

    while(!pq.empty() && pq.top()<day){
        pq.pop();
    }
    }
return count;

    }
};
