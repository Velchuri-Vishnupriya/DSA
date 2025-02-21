//S.C : O(n * 2^n) , total 2^n strings eaching having length n
class Solution {
public:
void solve(string& curr,string& res,int n,int k,int& count){
    if(curr.length()==n){
        count++;
        if(count==k) res=curr;
        return;
    }
    for(char ch='a';ch<='c';ch++){
      if(!curr.empty()&&curr.back()==ch)  continue;
      curr+=ch;
      solve(curr,res,n,k,count);
      if(!res.empty()) return;
      curr.pop_back();
    }
}
    string getHappyString(int n, int k) {
   string curr="";
   string res="";
   int count=0;
   solve(curr,res,n,k,count);
   return res;
    }
};
