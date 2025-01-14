//Brute Force
//Time and space complexity: O()    O(1)
class Solution {
public:
    int maxScore(string s) {
      int n=s.length();
      int result=INT_MIN;
      int i=0;
      while(i<n-1){
        int left_count=0;
        int right_count=0;
        for(int j=0;j<i+1;j++){
            if(s[j]=='0') left_count++;
        }
        for(int k=i+1;k<n;k++){
            if(s[k]=='1') right_count++;
        }
        i++;
        result=max(result,left_count+right_count);
              }
              return result;
    }
};

//Better Approach
//Time and Space complexity:
class Solution {
public:
    int maxScore(string s) {
int n=s.length();
int result=INT_MIN;
int total_ones=0;
for(int i=0;i<n;i++){
    if(s[i]=='1'){total_ones++;}
}
int zeros=0;
int ones=0;
for(int i=0;i<n-1;i++){
    if(s[i]=='1'){ones++;}
    else zeros++;
    result=max(result,(zeros+total_ones-ones));
}
    return result;}
};

//Best Approach
class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int score=INT_MIN;
        int ones=0;
        int zeros=0;
        int total_ones=count(begin(s),end(s),'1');
        for(int i=0;i<=n-2;i++){
if(s[i]=='1') ones++;
else zeros++;
score=max(score,zeros-ones);
        }
        return score+total_ones;
    }
};
