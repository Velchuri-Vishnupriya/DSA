//T.C : O(log n) n = size of vector 
//S.C : O(1)
class Solution {
public:
    int smallestNumber(int n) {
       vector<int>vec;
       for(int i = 0; i<10; i++){
        vec.push_back(pow(2,i+1)-1);
       }
       int i = lower_bound(vec.begin(), vec.end(), n) - vec.begin();
       return vec[i];
    }
};

//T.C : O(log n) n = size of vector 
//S.C : O(1)
class Solution {
public:
bool isResult(int x){
    return (x & (x+1)) == 0;
}
    int smallestNumber(int n) {
       int result = n;

       while(!isResult(result)){
        result++;
       }
       return result;
    }
};

//T.C : O(log n) n = size of vector 
//S.C : O(1)
class Solution {
public:
int smallestNumber(int n) {
       int result = 1;

       while(result < n){
        result = 2*result + 1;
       }
    return result;}
};

//T.C : O(log n) n = size of vector 
//S.C : O(1)
class Solution {
public:
int smallestNumber(int n) {
       int bits = log2(n) + 1;
       return (1 << bits) -1;
       }
};
