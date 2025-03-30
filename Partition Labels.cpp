//Using 2 pointer 
//T.C:O(n)
//S.C:O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {
     int n=s.length();
     vector<int> result;
     vector<int> mp(26,-1);
     for(int i=0;i<n;i++){
        int idx=s[i]-'a';
        mp[idx]=i;
     }   

     int i=0;
     while(i<n){
        int end=mp[s[i]-'a'];
        int j=i;
        while(j<end){
            end=max(end,mp[s[j]-'a']);
            j++;
        }
        result.push_back(j-i+1);
        i=j+1;
     }
     return result;
    }
};

//A better version of the previous code
class Solution {
public:
    vector<int> partitionLabels(string s) {
     int n=s.length();
     vector<int> result;
     vector<int> mp(26,-1);
     for(int i=0;i<n;i++){
        int idx=s[i]-'a';
        mp[idx]=i;
     }   

     int i=0;
     int start=0;
     int end=0;
     while(i<n){
        end=max(end,mp[s[i]-'a']);
       if(i==end){
        result.push_back(end-start+1);
        start=i+1;
       }
       i++;
     }
     return result;
    }
};
