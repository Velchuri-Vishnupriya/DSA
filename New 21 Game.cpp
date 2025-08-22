//Approach - 1 - Brute Force
//T.C : O(n*maxpts)
class Solution{
public:
    double new21Game(int n, int k, int maxpts){
        vector<double> P(n+1,0.0);
        //P[i] = prob of getting score = i;

        P[0] = 1;
//O(n*maxpts)
        for(int i=0; i<=n; i++){//O(n)
            for(int card=1; card<maxpts+1; card++){//O(maxpts)
                //prob of score card = 1/maxpts
                //remaining Score = P[i - card]
                if(i-card >= 0 && i-card < k){
                    P[i] += P[i-card]/maxpts;
                }
            }
        }
        // k to n tak ka probaility nikalna hai
        return accumulate(begin(P)+k,end(P),0.0);
    }    
};

//Approach - 2
//T.C : O(n)
class Solution{
public:
    double new21Game(int n, int k, int maxpts){
        vector<double> P(n+1, 0.0);
        P[0] = 1.0;

        double currProbabSum = (k == 0) ? 0.0 : 1.0;

        for (int i = 1; i <= n; i++) {
            P[i] = currProbabSum / maxpts;

            if (i < k) {
                currProbabSum += P[i]; 
            }
            if (i - maxpts >= 0 && i - maxpts < k) {
                currProbabSum -= P[i - maxpts];
            }
        }
        return accumulate(begin(P) + k, end(P), 0.0);
    }
};
