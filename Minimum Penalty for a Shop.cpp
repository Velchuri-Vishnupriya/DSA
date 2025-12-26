//T.C : O(n + n + n) ~ O(n)
//S.C : O(n + n)
class Solution {
public:
    int bestClosingTime(string customers) {
      vector<int> beforeJ;
      vector<int> afterJ;

      customers.push_back('S');
      
      int n = customers.size();
      int penaltyBeforeJ = 0;
      int penaltyAfterJ = 0;
      int totalY = count(customers.begin(), customers.end(), 'Y');//O(n)

      for(int j = 0; j < n; j++){//O(n)
        //let j be the closing hour 
        beforeJ.push_back(penaltyBeforeJ);
        if(customers[j] == 'N') penaltyBeforeJ++;

        afterJ.push_back(totalY - penaltyAfterJ);
        if(customers[j] == 'Y') penaltyAfterJ++;
      }

      int ans = INT_MAX;
      int jIdx = n;

      for(int j = 0; j < n; j++){//O(n)
        if(afterJ[j] + beforeJ[j] < ans){
            ans = afterJ[j] + beforeJ[j];
            jIdx = j;
        }
      }

      return jIdx;
    }
};
