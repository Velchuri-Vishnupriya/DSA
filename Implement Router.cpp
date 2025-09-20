// T.C. : 
// addPacket()       -> O(k) worst-case (due to forwardPacket() + vector erase at front)
// forwardPacket()   -> O(k) worst-case (erase from vector front for destination timestamps)
// getCount()        -> O(log k) per query (binary search in vector)
// k = number of packets for a particular destination

// S.C. : 
// O(MAX_SIZE) total
// packetStore     -> O(MAX_SIZE)
// que             -> O(MAX_SIZE * key length)
// destTimestamps  -> O(MAX_SIZE)
class Router {
public:
    int MAX_SIZE;
    unordered_map<string, vector<int>> packetStore;
    unordered_map<int, vector<int>> destTimeStamps;
    queue<string> que;

    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }
    string makeKey(int s, int d, int t){
        return to_string(s) + "_" + to_string(d) + "_" + to_string(t);
    }
    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);

        if(packetStore.find(key) != packetStore.end()) return false;

        if((int)packetStore.size() >= MAX_SIZE){forwardPacket();}

        packetStore[key] = {source,destination,timestamp};
        que.push(key);
        destTimeStamps[destination].push_back(timestamp);
        return true;

    }

    vector<int> forwardPacket() {
       if(packetStore.empty()) return {};

       string key = que.front();
       que.pop();

       vector<int> packet = packetStore[key];
       packetStore.erase(key);

       int dest = packet[1];
       destTimeStamps[dest].erase(destTimeStamps[dest].begin());

       return packet;
    }
    
   
    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimeStamps.find(destination);
        if(it == destTimeStamps.end() || it->second.empty()) return 0;

        int i = lower_bound(begin(it->second), end(it->second), startTime) - begin(it->second);
        int j = upper_bound(begin(it->second), end(it->second), endTime)-begin(it->second);

        return j - i;
    }
};
