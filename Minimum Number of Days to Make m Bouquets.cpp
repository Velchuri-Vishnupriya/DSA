//T.C : O(n * log(max_ele - min_ele))
//S.C : O(1)
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(begin(bloomDay), end(bloomDay));
        int high = *max_element(begin(bloomDay), end(bloomDay));

        //n shd be such a day where the nummber of bloomed flowers is m*k and ADJAcENT

        int n = bloomDay.size();
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            int bouquets = 0;
            /*I have to write a logic here which updates bloomedFlowers variable
            Like a for loop runnign for m flowers and each time i check whethr k flowers bloomed or not without revisiting the aldready used k flowers*/
            int i = 0;
            int sum = 0;
            int prev = bloomDay[0];
            
     while(i < n){
        sum += bloomDay[i] <= mid ? 1 : 0;
        if(sum == k){
            bouquets++;
            sum = 0;
        }else if(bloomDay[i] > mid){
            sum = 0;
        }
        i++;
     }
            if(bouquets >= m){
                ans = min(ans, mid);
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
   return ans < INT_MAX ? ans : -1; }
};
