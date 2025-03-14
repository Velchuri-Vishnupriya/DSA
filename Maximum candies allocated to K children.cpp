//Brute Force- Time Limit exceeded;
//T.C: O(n*maxC)
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {int maxC=0;
    int n=candies.size();
    for(int i=0;i<n;i++){
        maxC=max(maxC,candies[i]);
    }

    for(int c=maxC;c>=1;c--){
        long long count=0;
        for(int i=0;i<n;i++){
            count+=candies[i]/c;
        }
        if(count>=k) return c;
    }
  return 0;  }
};

//Better Opproach
//T.C: O(long(maxC) * n)
class Solution {
public:
int n;

int candis(vector<int>& candies,long long k,int mid){
    long long count=0;
    for(int i=0;i<n;i++){
count+=candies[i]/mid;
}
return (count>=k) ? 1: 0;
}
    int maximumCandies(vector<int>& candies, long long k) {int maxC=0;
    n=candies.size();
    for(int i=0;i<n;i++){
        maxC=max(maxC,candies[i]);
    }

int l=1;
int r=maxC;
int result=0;
while(l<=r){
int mid=l+(r-l)/2;
if(candis(candies,k,mid)){result=mid; l=mid+1;}
else {r=mid-1;}
}
  return result;  }
};
