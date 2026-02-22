//Approach - 1
//T.C : O(log n)
//S.C : O(log n)
class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        vector<int> onesPositions;
        string s = "";
        while(n){
            s += ((n % 2) + '0');
            n /= 2;
        }
        reverse(s.begin(), s.end());
        int i = 0;
        for(char ch : s){
            if(ch == '1')onesPositions.push_back(i);
            i++;
        }

        if(onesPositions.size() <= 1)return 0;

        for(int j = 1; j < onesPositions.size(); j++){
            ans = max(onesPositions[j] - onesPositions[j-1], ans);
        }

        return ans;
    }
};

//Approach - 2
//T.C : O(log n)
//S.C : O(1)
class Solution {
public:
    int binaryGap(int n) {
       int curr = 0;
       int prev = -1;

       int result = 0;

       while(n){
        if((n&1) > 0){
            result = (prev != -1) ? max(result, curr - prev) : result;
            prev = curr;
        }
        curr++;
        n >>=1;
       }

       return result;
    }
};

//Approach - 3
//T.C : O(32) ~ O(1)
//S.C : O(1)
class Solution {
public:
    int binaryGap(int n) {
       int curr = 0;
       int prev = -1;

       int result = 0;

       for(curr = 0; curr < 32; curr++){
        if(((n >> curr) & 1) > 0){
            result = (prev != -1) ? max(result, curr - prev) : result;
            prev = curr;
        }
       }
       return result;
    }
};
