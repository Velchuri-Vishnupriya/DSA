//Using Dijkstra Algorithm
//T.C : O(n*m * log(n*m))
//S.C: O(n*m) //result array + priority queue
class Solution {
public:
vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        typedef pair<int ,pair<int,int>> P;
     int n=moveTime.size();
     int m=moveTime[0].size();

     vector<vector<int>> result(n,vector<int>(m,INT_MAX));
     priority_queue<P ,vector<P> ,greater<P>> pq;

result[0][0]=0;
pq.push({0,{0,0}});
while(!pq.empty()){
    int currTime = pq.top().first;
    pair<int,int> cell =pq.top().second;
    int i=cell.first;
    int j=cell.second;
    pq.pop(); //push and pop takes O(log (n*m));
     
     if(i==n-1 && j==m-1) return currTime;

     for(auto& dir : directions){
        int i_=i+dir[0];
        int j_=j+dir[1];

        if(i_>=0 && i_<n && j_>=0 && j_<m){
            int wait= max (moveTime[i_][j_] - currTime , 0);
            int newTime = wait + currTime+1;
            if(newTime<result[i_][j_]) {pq.push({newTime , {i_,j_}});
            result[i_][j_] = newTime;  } 
            
        }
     }

}
  return -1;  }
};
