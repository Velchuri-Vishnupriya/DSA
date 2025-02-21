//One of the best approaches
//T.S: O(n)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string result="";
        for(int i=0;i<n;i++){
            char ch=nums[i][i];
            if(ch=='0') result+='1';
            else result.push_back('0');
        }
        return result;
    }
};
//Approach 2
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string result="";
       unordered_set<int> st;
       for(string &num:nums){
        st.insert(stoi(num,0,2));
       }
       for(int i=0;i<=n;i++){
        if(st.find(i)==st.end()){result=bitset<16>(i).to_string();
        break;}
       }
       return result.substr(16-n,n);
    }
};

//using backtracking 
//T.S : O(2^n)
class Solution {
public:
string solve(unordered_set<string> numset,  string& current,int n)
{
    if(current.length()==n){
        if(numset.find(current)==numset.end()) return current;
        else return "";
    }

    current+='0';
    string res=solve(numset,current,n);
    if(!res.empty()) return res;
    current.pop_back();

    current+='1';
     res=solve(numset,current,n);
    if(!res.empty()) return res;
    current.pop_back();

    return "";

}    string findDifferentBinaryString(vector<string>& nums) {
       int n=nums.size();
       string current;
       unordered_set<string> numset(begin(nums),end(nums));
       return solve(numset,current,n);
    }
};
