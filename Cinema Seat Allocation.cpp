//Approach1
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {unordered_map<int,unordered_set<int>>mp; //row->seats in each row booked

    for(auto& reservedSeat : reservedSeats){//O(n)
        int row = reservedSeat[0];
        int seat = reservedSeat[1];
        mp[row].insert(seat);
    }

    int result = (n-mp.size())*2;

    for(auto&[row, bookedSeats] : mp){//O(n)
        auto isAvailable = [&](int seat){//O(10)
            return bookedSeats.find(seat) == bookedSeats.end();
        };
        bool groupA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
        bool groupB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
        bool groupC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);
        if(groupA && groupC){
            result += 2;
        }else if(groupA || groupB || groupC){
            result += 1;
        }
    }
        
    return result;}
};

//Approach2 using BitMask for space optimization
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int>mp; //row->seats in each row booked

    for(auto& reservedSeat : reservedSeats){//O(n)
        int row = reservedSeat[0];
        int seat = reservedSeat[1];
        mp[row] = (mp[row] | (1<<seat));
    }

    int result = (n-mp.size())*2;
    int maskA = (1<<2)|(1<<3)|(1<<4)|(1<<5); 
    int maskB = (1<<4)|(1<<5)|(1<<6)|(1<<7);
    int maskC = (1<<6)|(1<<7)|(1<<8)|(1<<9);

    for(auto&[row, bookedSeatsMask] : mp){//O(n)

        bool groupA = (bookedSeatsMask & maskA) == 0;
        bool groupB = (bookedSeatsMask & maskB) == 0;
        bool groupC = (bookedSeatsMask & maskC) == 0;
        if(groupA && groupC){
            result += 2;
        }else if(groupA || groupB || groupC){
            result += 1;
        }
    }
        
    return result;}
};
