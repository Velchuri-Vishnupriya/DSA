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
