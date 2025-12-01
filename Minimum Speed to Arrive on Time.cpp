//T.C : O(n * log(1e7))
//S.C : O(1)
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 1e7;
        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high - low)/2;
            double hours = 0.0;
            for(int i = 0; i < dist.size(); i++){
                if(i == dist.size()-1) {
                    hours+= (double(dist[i])/mid);
                    }else{
                        hours+= ceil(double(dist[i])/mid);
                    }

            }
            if(hours <= hour){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
   return ans == INT_MAX ? -1 : ans;
    }
};
