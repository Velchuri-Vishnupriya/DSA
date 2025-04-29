//Sliding Window
//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& v, int k) {
        auto it=max_element(v.begin(),v.end());
        int maxElement = *it;
        int i=0;
        int j=0;
        int n=v.size();
        long long result=0;
        long long count=0;
        while(j<n){
if(v[j]==maxElement){
    count++;
    while(i<n && count>=k){
           result+=(n-j);
        if(v[i]==maxElement) count--;
        i++;
     
    }
}
        j++;}
    return result;}
};
