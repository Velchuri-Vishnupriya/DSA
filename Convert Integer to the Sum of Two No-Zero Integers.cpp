//Brute Force
//T.C : O(n*log n)
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
    for(int i=1; i<n; i++){
    string s1 = to_string(i);
    string s2 = to_string(n-i);
    if((s1.find('0')==string :: npos) && (s2.find('0') == string::npos)) return {i,n-i};
    }

    return {1,1};
    }
};

//Optimal
//T.C : O(log n)
//T.C : O(log n)
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = n;
        int b = 0;
        int placeValue = 1;

        // a + b = n
        while (n > 1) {
            int take = 1;
            if (n % 10 == 1) take = 2;  // avoid zero digit

            a -= take * placeValue;
            b += take * placeValue;

            n = (n - take )/10;               // move to next digit
            placeValue *= 10;
        }

        return {a, b};
    }
};

