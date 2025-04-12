//T.C:O(10^d * n log n)
//S.C:(10^d)
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
       unordered_set<string> st;

       int d=(n+1)/2;
       int start=pow(10,d-1);
       int end=pow(10,d)-1;

       for(int num=start;num<=end;num++){//O(10^d)
         string lefthalf=to_string(num);
         string full="";
         if(n%2==0){
            string righthalf=lefthalf;
            reverse(righthalf.begin(),righthalf.end());
            full=lefthalf+righthalf;
         }
         else{
             string righthalf=lefthalf.substr(0,d-1);
             reverse(righthalf.begin(),righthalf.end());
             full=lefthalf+righthalf;
         }

         long long number=stoll(full);
         if(number %k !=0) continue;
          sort(full.begin(),full.end());//n log n
          st.insert(full);
       } 

       vector<long long> factorial(11,1);

       for(int i=1;i<11;i++){
factorial[i]=factorial[i-1]*i;
       }

long long result=0;

       for(const string& s: st){//O(10^d)
        vector<long long> count(10,0);
        for(const char& ch:s){
            count[ch-'0']++;
        }
int totaldigits=s.length();
int zerodigits=count[0];
int nonzerodigits=totaldigits-zerodigits;

long long perm=(nonzerodigits*factorial[totaldigits-1]);
       
        for(int i=0;i<10;i++){
            if(count[i]==0) continue;
            perm/=factorial[count[i]];
                    }
                    result+=perm;
       }
       return result;

    }
};
