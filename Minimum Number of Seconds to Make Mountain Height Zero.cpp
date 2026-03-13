//T.C : O(log(r-l)*workerTimes) 
//~O(n log T)n = workerTimes T = min * H * (H+1)/2
//S.C : O(1)

class Solution {
public:

bool check(vector<int>& workerTimes,int mountainHeight,long long mid){
long long total = 0;

for(auto& worker : workerTimes){//O(workerTimes)
long long k = (-1 + sqrt(1.0 + (8.0 * mid)/worker))/2;
total += k;
if(total >= mountainHeight) return true;
}
return total >= mountainHeight;
}

long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

    long long l = 1;

    long long minWorker = *min_element(workerTimes.begin(), workerTimes.end());

    long long r = minWorker * 1LL * mountainHeight * (mountainHeight+1) / 2;

    long long result = r;

    while(l <= r){//O(r - l)

        long long mid = l + (r-l)/2;

        if(check(workerTimes, mountainHeight, mid)){
            result = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }

   return result; 
}
};
