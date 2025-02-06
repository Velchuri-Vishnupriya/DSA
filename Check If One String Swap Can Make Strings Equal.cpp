//Optimal Approach
//T.C : O(n)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length(); int n1=s2.length();
        if(n1!=n) return false;
        if(s1==s2) return true;
       vector<int> diff;
       for(int i=0;i<n;i++){
        if(s1[i]!=s2[i]){diff.push_back(i);}
        if(diff.size() >2) return false;
       }
      if(diff.size() !=2 ) return false;
      int i=diff[0]; int j=diff[1];
      swap(s1[i],s1[j]);
      if(s1==s2) return true;
      else return false;
    }
};
