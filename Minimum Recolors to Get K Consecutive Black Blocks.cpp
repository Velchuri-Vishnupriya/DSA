//Approach-1 - Brute Force
//T.S: O(n^2)
//S.C: O(1)

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
    int n=blocks.length();
    int result=INT_MAX;
    for(int i=0;i<=n-k;i++){
        int w=0;
        for(int j=i;j-i+1<=k;j++){
            if(blocks[j]=='W') w++;
        }
    result=min(result,w);
    }
    return result;
    }
};

//Approach-2 - Sliding Window
//T.S: O(n)
//S.C: O(1)

 class Solution {
public:
    int minimumRecolors(string blocks, int k) {
    int n=blocks.length();
 int ops=k;
 int i=0; 
 int j=0;
 int w=0;
 while(j<n)
 {
if(blocks[j]=='W') w++;
if(j-i+1==k){
    ops=min(ops,w);
    if(blocks[i]=='W'){w--;}
    i++;
}
j++;
 }  
 return ops; }
}; 
