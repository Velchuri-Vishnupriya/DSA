//T.C : constructor : O(n log n) changeRating : O(log m) highestRated : O(1)
//S.C :  food_info = O(n) cusine_map = O(n)
class FoodRatings {
public:
typedef pair<string, int> PF;
typedef pair<int,string> PC;
unordered_map<string, PF> food_info; // food -> {cusine, rating}
unordered_map<string, set<PC>> cuisine_map; // cuiisines -> set(rating, food)
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++)
        {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            food_info[food] = {cuisine, rating};
            cuisine_map[cuisine].insert({-rating, food});
        }
    }
   
    void changeRating(string food, int newRating) {
       auto& info = food_info[food];
       
       string cuisine = info.first;
       int oldRating = info.second;

       cuisine_map[cuisine].erase({-oldRating, food});
       
       info.second = newRating;

       cuisine_map[cuisine].insert({-newRating, food});
    }
   
    string highestRated(string cuisine) {
       return cuisine_map[cuisine].begin()->second;
        }
};
