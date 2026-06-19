//Approach-1 -> using extra space
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> altitude(n+1);
        altitude[0] = 0;

        for(int i=1; i<=n; i++){
            altitude[i] = altitude[i-1] + gain[i-1];
        }
        return *max_element(begin(altitude), end(altitude));

        int n = gain.size();
        int start = 0;
        int maxAlt = 0;

        for(int i=0; i<n; i++){
            start += gain[i];
            if(start > maxAlt) maxAlt = start;
        }
        return maxAlt;
    }
};

//Approach-2 -> w/o using extra space
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int start = 0;
        int maxAlt = 0;

        for(int i=0; i<n; i++){
            start += gain[i];
            if(start > maxAlt) maxAlt = start;
        }
        return maxAlt;
    }
};
