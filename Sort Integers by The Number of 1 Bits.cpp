//Approach - 1
//T.C: O(nlogn)
//S.c: O(n) -- min heap stack space
class Solution {
public:
typedef pair<int , int> P; //no.of ones , num
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<P , vector<P>, greater<P>> pq;
        vector<int> ans;
        for(auto& num : arr){//O(n)
            int countOnes = 0;
            for(int k=0; k<=31; k++)//O(32)
            {
                int temp = 1<<k;
                if((num & temp) != 0) countOnes++;
            }
            pq.push({countOnes , num }); //O(log n)
          }
while(!pq.empty()){ //O(n)
    ans.push_back(pq.top().second);
    pq.pop(); //O(log n)
}
    
   return ans; }
};

//Approach - 2
//T.C: O(NlogN * log(no.of digits))
//S.C: O(1)
class Solution {
public:
int countOneBits(int num){
   int count = 0 ; 
   while(num){
count += (num & 1);
num = num >> 1;
    }
    return count;
}
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [&](int a, int b){
int count_a = countOneBits(a);
int count_b = countOneBits(b);
if(count_a == count_b) return a < b;
return count_a < count_b;
        };
        sort(begin(arr), end(arr), lambda);
   return arr;  }
};

//Aprroach - 3 -> using builtin STL function
//T.C: O(NlogN)
//S.C: O(1)
class Solution {
public:
 vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [&](int a, int b){
int count_a = __builtin_popcount(a); //O(1)
int count_b = __builtin_popcount(b);
if(count_a == count_b) return a < b;
return count_a < count_b;
        };
        sort(begin(arr), end(arr), lambda);
   return arr;  }
};
