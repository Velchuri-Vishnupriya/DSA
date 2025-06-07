//Approach -1
//T.C: O(nlogn)
//S.C: O(n)
class Solution {
public:
typedef pair<char , int> P;
    string clearStars(string s) {
    priority_queue<P , vector<P>, greater<> > pq;
    for(int i=0; i<s.length(); i++){//O(n)
        if(s[i]=='*'){
            if(!pq.empty()) {auto it = pq.top();
            pq.pop(); //O(log n)
            int idx = it.second;
            idx*= (-1);
            s[idx] = '*'; }
        }
        else{
            pq.push({s[i],(-1*i)}); //O(n)
        }
    }
   string result="";
   for(int i=0;i<s.length();i++){
    if(s[i]!='*') result+=s[i];
   } 
   return result;}
};

//Approach - 2
//T.C: O(nlogn)
//S.C: O(n)
class Solution {
public:
    typedef pair<char, int> P;

    struct comp{
        bool operator()(P &p1, P& p2){
            if(p1.first == p2.first) {
                return p1.second < p2.second;
            }

            return p1.first > p2.first;
        }
    };
 string clearStars(string s) {
        int n = s.length();

        priority_queue<P, vector<P>, comp> pq;

        for(int i = 0; i < n; i++) { //O(n)
            if(s[i] != '*') {
                pq.push({s[i], i}); //log(n)
            } else {
                int idx = pq.top().second;
                pq.pop();
                s[idx] = '*';
            }
        }

        string result = "";
        for(int i = 0; i < n; i++) {
            if(s[i] != '*') {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};
