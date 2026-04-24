//Approach - 1 -> 2 Pass
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        //once try considering all _ as L
        int dist = 0;
        int maxDist = 0;
        for(auto& ch : moves){
            if(ch == 'L' || ch == '_'){
                dist -= 1;
            }else{
                dist += 1;
            }
        }
        maxDist = dist;
        dist = 0;
        //try with _ as R
        for(auto& ch : moves){
            if(ch == 'R' || ch == '_'){
                dist += 1;
            }else{
                dist -= 1;
            }
        }
    return max(abs(dist), abs(maxDist));
    }
};

//Approach - 2 - One pass Solution
//T.C : O(n)
//s.C : O(1)
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
       int left = 0;
       int right = 0;
       int dash = 0;
       for(auto& ch : moves){
        if(ch == 'L')left++;
        else if(ch == 'R')right++;
        else dash++;
       }
    return abs(right - left) + dash;
    }
};
