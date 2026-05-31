//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    bool asteroidsDestroyed(int mass1, vector<int>& asteroids) {
        //return false if maass of the planet < mass of asteroid
        //mass_p > mass_a
        //ascending order
        long long mass = (long long)mass1;
        sort(begin(asteroids), end(asteroids));
        for(auto& mass_a : asteroids){
            if((long long)mass_a > mass)return false;
            else mass += (long long)mass_a;
        }
        return true;
    }
};
