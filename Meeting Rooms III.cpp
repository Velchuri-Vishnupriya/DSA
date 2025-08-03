//Brute Force
//T.C : O(m * log m + m * n)
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
    int m = meetings.size();

    sort(begin(meetings), end(meetings));//sort the vector based on starting  time

    vector<long long> lastAvailableAt(n,0); //lastAvailable[i] = Room number i will be last avialable at

    vector<int> roomsUsedCount(n,0); //roomsUsedCount[i] = Room i is used how many times

    for(vector<int>& meet: meetings){
        
        int start = meet[0];
        int end = meet[1];
        bool found = false;
        long long  duration = end - start;

        long long  earlyEndRoomTime = LLONG_MAX;
        int earlyEndRoom = 0;

        //Find the first available meeting room for my current meeting
        for(int room = 0; room < n; room++){
            if(lastAvailableAt[room] <= start){
                lastAvailableAt[room] = end; //current meeting will finish at end
                found = true;
                roomsUsedCount[room]++;
                break;
            }

            if(lastAvailableAt[room] < earlyEndRoomTime){
                earlyEndRoomTime = lastAvailableAt[room];
                earlyEndRoom     = room;
            }
        }

        if(found != true){//we couln't find any free room
          //Pick that room which WILL end early
          lastAvailableAt[earlyEndRoom] += duration;
          roomsUsedCount[earlyEndRoom]++;
        }
    }
    int res = -1;
    int maxUse = 0;
     for(int room = 0; room < n; room++){
        if(roomsUsedCount[room] > maxUse){
            res = room;
            maxUse = roomsUsedCount[room];
        }
     }
   return res; }
};

//Optimized version
//T.C : O(m*log m + m*log n)
class Solution {
public:
    typedef pair<long long,int> P; //{duration,room number}
    int mostBooked(int n, vector<vector<int>>& meetings) {
    int m = meetings.size();

    //O(m*log m)
    sort(begin(meetings), end(meetings));//sort the vector based on starting  time

    vector<int> roomsUsedCount(n,0); //roomsUsedCount[i] = Room i is used how many times

priority_queue<P, vector<P>, greater<P>> usedRooms;

priority_queue<int, vector<int>, greater<int>> availableRooms;

for(int i = 0; i <n; i++){//O(n)
    availableRooms.push(i);
}

for(auto& meet : meetings){//O(m)
    int start = meet[0];
    int end   = meet[1];
    int duration = end - start;
    while(!usedRooms.empty() && usedRooms.top().first <= start){
        auto Pair = usedRooms.top();
        usedRooms.pop(); //O(log n )
        int room = Pair.second;
        availableRooms.push(room);
    }

    if(!availableRooms.empty()){
        int room = availableRooms.top();
        usedRooms.push({end,room});
        availableRooms.pop();
        roomsUsedCount[room]++;
    }else{
        //we don't have aby room available 
        int room = usedRooms.top().second;
        long long endTime = usedRooms.top().first;
        usedRooms.pop();
        usedRooms.push({endTime + duration, room});
         roomsUsedCount[room]++;
    }
}
    int res = -1;
    int maxUse = 0;
     for(int room = 0; room < n; room++){
        if(roomsUsedCount[room] > maxUse){
            res = room;
            maxUse = roomsUsedCount[room];
        }
     }
  return res; }
};
