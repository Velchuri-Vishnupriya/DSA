//T.C : O(n * log(max - min))
//S.C : O(1)
class Solution {
public:
bool possible(int force, vector<int>& position, int m){
    int prev = position[0];
    int countBalls = 1;

    for(int i = 1; i < position.size(); i++){
        int curr= position[i];

        if(curr - prev >= force){
            countBalls++;
            prev = curr;
        }

        if(countBalls == m) break;
    }
    return countBalls == m ? true : false;
}
    int maxDistance(vector<int>& position, int m) {
        //maximize the minimum
        int low = 1;
        int high = *max_element(begin(position), end(position)) - *min_element(begin(position), end(position));
int ans = 1;
sort(begin(position), end(position));

        while(low <= high){//O(log(max - min))
int midForce = low + (high - low);

if(possible(midForce, position, m)){
    ans = midForce;
    low = midForce + 1;
}else{
    high = midForce - 1;
}
        }
   return ans;
    }
};
