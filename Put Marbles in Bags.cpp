class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
int n=weights.size();
int m=n-1;
vector<int> pairsum(m,0);

for(int i=0;i<m;i++){
    pairsum[i]=weights[i]+weights[i+1];
} 
sort(begin(pairsum),end(pairsum));
long minsum=0; long maxsum=0; 
for(int i=0;i<k-1;i++){
    minsum+=pairsum[i];
    maxsum+=pairsum[m-i-1];
}
   return maxsum-minsum;}
};
