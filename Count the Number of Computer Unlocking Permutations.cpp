//Approach - 1
//T.C : O(n*log n)
//S.C : O(1)
class Solution {
public:
const int M = 1e9 + 7;
long long fact(int x){
    long long factorial = 1;
    for(int i = 1; i <= x; i++){
        factorial = (factorial * i) % M;
    }
    return factorial;
}
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        sort(begin(complexity) + 1, end(complexity));//O(n*log n)
        int code = complexity[0];
        if(complexity[1] > complexity[0]) return fact(n-1);//O(n-1)
        return 0;
    }
};

//Approach - 2
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
const int M = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        long long result = 1;
        for(int i = 1; i < n; i++){
            if(complexity[i] <= complexity[0]) return 0;
            result = (result * i) % M;
        }
    return result;}
};
