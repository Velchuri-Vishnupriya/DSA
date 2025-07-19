//Brute Force
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    
    for(int i=0; i<n; i++){
        if(gas[i] < cost[i]) continue;

        int j = (i + 1) % n;
        
        int costForMovingFromThisStation = cost[i];
        
        int gasEarnInNextStationj = gas[j];

        int currGas = gas[i] - costForMovingFromThisStation + gasEarnInNextStationj;

     while(j != i){
        if(currGas < cost[j]) break;

        int costForMovingFromThisj = cost[j];

        j = (j + 1)%n;

        int gasEarnInNextStationj = gas[j];

        currGas = currGas - costForMovingFromThisj + gasEarnInNextStationj;
     }  
     if(j == i) return i; 
    }
    return -1;
    }
};

//Using Greedy
//T.C : O(n)
//S.C : O(1)
class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
   int totalKamai = accumulate(begin(gas), end(gas), 0);
   int totalKharch = accumulate(begin(cost), end(cost), 0);

   if(totalKamai < totalKharch) return -1;

   int n = gas.size();
int res = 0;
int total = 0;
   for(int i=0; i<n; i++){
total += (gas[i] - cost[i]);
if(total < 0) {
    res = i+1;
    total = 0;
}
   } 
    return res;}
};
