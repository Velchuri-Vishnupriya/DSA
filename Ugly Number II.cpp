//Approach - 1  -> Using heap + unordered_set data structure
//T.C : O(n*logn) -> Push and Pop operations of Heap
//S.C : O(n) -> heap + unorderedset
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1 , 0);
        priority_queue<long long ,vector<long long>, greater<long long >> pq;
        unordered_set <long long > seen;
        int i = 1;
        pq.push(1);
        seen.insert(1);
        while(i <=n){
arr[i] = pq.top();
int num = pq.top();
pq.pop();
if(seen.count((long long)num*2)==0){
    seen.insert((long long )num*2);
     pq.push((long long)num*2);
     }
if(seen.count((long long)num*3)==0){
    seen.insert((long long)num*3);
     pq.push((long long)num*3);
     }
if(seen.count((long long )num*5)==0){
    seen.insert((long long)num*5);
     pq.push((long long)num*5);
     }
i++;
  }
return arr[n]; }
};

//Approach - 2 -> Using DP
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n + 1, 0);
        // t[i] = ith ugly number
        // t[n] = nth ugly number

        int i2 = 1, i3 = 1, i5 = 1;

        arr[1] = 1; // 1st ugly number is 1

        for (int i = 2; i <= n; i++) {
            int i2UglyNum = arr[i2] * 2;
            int i3UglyNum = arr[i3] * 3;
            int i5UglyNum = arr[i5] * 5;

            int minUglyNum = min({i2UglyNum, i3UglyNum, i5UglyNum});
            arr[i] = minUglyNum;

            if (minUglyNum == i2UglyNum) i2++;
            if (minUglyNum == i3UglyNum) i3++;
            if (minUglyNum == i5UglyNum) i5++;
        }

        return arr[n];
    }
};
