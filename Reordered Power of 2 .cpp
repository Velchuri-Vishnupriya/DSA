//4 - Approaches

//Aproach - 1
//T.C : O(n*log n) - generic complexity = O(1)
class Solution {
public:
    bool reorderedPowerOf2(int n) {
       string s = to_string(n);
       sort(begin(s), end(s));
//check all 2 powers and see if it maches the given num
//2^29
       for(int p = 0; p <= 29; p++){//O(29*n*log n) 10 digits
        string s1 = to_string(1 << p);
        sort(begin(s1), end(s1));
        if(s == s1) return true;
       }
       return false;
    }
};

//Aproach - 2
//Using Unordered set 
class Solution {
public:
    unordered_set<string> st;
    void buildSet(){
        //2^p from p =0 to 29
        //convert to string , sort , store in set
        for(int p =0; p <= 29; p++){
            string s = to_string(1 << p);
            sort(begin(s), end(s));
            st.insert(s);
        }
    }
    bool reorderedPowerOf2(int n) {
      if(st.empty()){
        buildSet(); // call only once(static)
      }

      string s = to_string(n);//O(d)
      sort(begin(s), end(s));//dlogd
      if(st.count(s) != 0) return true;
       return false;
    }
};

//Aproach - 3
//Using Vectors
class Solution {
public:
    vector<int> getVectorCountFormat(int n){
        vector<int> vec(10, 0);

        while(n){
            vec[n % 10]++;
            n /= 10;
        }
        return vec;
    }
    bool reorderedPowerOf2(int n) {
      vector<int> vec1;
      vec1 = getVectorCountFormat(n);

      for(int p = 0; p <= 29; p++){
        if(vec1 == getVectorCountFormat(1<<p)) return true;
      }
    return false;}
};

//Aproach - 4
//Using an integer variable
class Solution {
public:
    int getCountFormat(int n){
        vector<int> vec(10, 0);
        int num = 0;
        while(n){
            num += pow(10, n%10);
            n /= 10;
        }
        return num;
    }
    bool reorderedPowerOf2(int n) {
   int input = getCountFormat(n);

      for(int p = 0; p <= 29; p++){
        if(input == getCountFormat(1<<p)) return true;
      }
    return false;}
};
