//Approach-1
//T.S: O(n)
//S.C: O(n)
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int> original(n);
        original[0]=0;
        for(int i=0;i<n-1;i++){
original[i+1]=derived[i]^original[i];
        }
        if(derived[n-1]==original[n-1]^original[0]){
return true;
        }
             original[0]=1;
        for(int i=0;i<n-1;i++){
original[i+1]=derived[i]^original[i];
        }
        if(derived[n-1]==original[n-1]^original[0]){
return true;
}
return false;}
};

//Approach-2
//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        int Xor=0;
for(int i=0;i<n;i++){
    Xor^=derived[i];
}
if(Xor==0) return true;
else{return false;}}
};
