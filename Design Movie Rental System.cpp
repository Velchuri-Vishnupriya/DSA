//T.C :
/* 
MovieRentingSystem constructor - O(E*log(E))
search : O(5)
rent : O(log(n) + log(R))
drop : O(log(n) + log(R))
report: O(5)
*/
//S.C : 
/*price map -> O(E)
avilable set -> O(E)
rented -> O(R)
*/
class MovieRentingSystem {
public:
    //price lookup: (shop,movie) -> price
    map<pair<int,int>,int> price;

    //available movies 
    unordered_map<int,set<tuple<int,int,int>>> available;

    //global rented set
    set<tuple<int,int,int>>rented;

    int N;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {//O(E.log(k))
        N = n;
        for(auto &e : entries) {
            int shop = e[0], movie = e[1], cost=e[2];
            price[{shop,movie}] = cost;//O(log E)-becuase it is ordered map
            available[movie].insert({cost,shop,movie});//log(k) set takes logk for insertion
        }
    }

    vector<int> search(int movie) {//O(5)
        vector<int> res;
        auto& s = available[movie];
        int k = 0;
        for(auto&[cost,shop,mv]: s){
            res.push_back(shop);
            if(++k == 5)break;
        }
        return res;
    }

    void rent(int shop, int movie) {//O(log(n)+log(R))
      int cost =  price[{shop,movie}];
      available[movie].erase({cost,shop,movie});//O(log(n))
      rented.insert({cost,shop,movie});//O(log(R))
    }

    void drop(int shop, int movie) {
        int cost = price[{shop,movie}];
        rented.erase({cost,shop,movie});//O(log(R))
        available[movie].insert({cost,shop,movie});//O(log(n))
    }

    vector<vector<int>> report() {//O(5)
        vector<vector<int>> res;
        int k=0;
        for(auto& [cost,shop,mv]: rented){
            res.push_back({shop,mv});
            if(++k == 5) break;
        }
        return res;
    }
};
